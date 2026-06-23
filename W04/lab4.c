#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

/* Write every byte in the buffer, even if write() completes only partially. */
static int write_all(int fd, const char *buffer, ssize_t byte_count)
{
    ssize_t total_written = 0;

    while (total_written < byte_count) {
        ssize_t written = write(fd,
                                buffer + total_written,
                                (size_t)(byte_count - total_written));

        if (written == -1) {
            if (errno == EINTR) {
                continue;
            }

            return -1;
        }

        total_written += written;
    }

    return 0;
}

int main(int argc, char *argv[])
{
    int input_fd = -1;
    int output_fd = -1;
    int exit_status = EXIT_FAILURE;
    char buffer[BUFFER_SIZE];
    struct stat input_info;
    struct stat output_info;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <file1> <file2>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], argv[2]) == 0) {
        fprintf(stderr, "Error: file1 and file2 must be different files.\n");
        return EXIT_FAILURE;
    }

    /* file2 is the input and must remain unchanged. */
    input_fd = open(argv[2], O_RDONLY);
    if (input_fd == -1) {
        perror("Error opening file2");
        goto cleanup;
    }

    /* O_APPEND preserves file1 and places every write at its end. */
    output_fd = open(argv[1], O_WRONLY | O_APPEND);
    if (output_fd == -1) {
        perror("Error opening file1");
        goto cleanup;
    }

    /* Also reject different pathnames that refer to the same physical file. */
    if (fstat(input_fd, &input_info) == -1 ||
        fstat(output_fd, &output_info) == -1) {
        perror("Error checking files");
        goto cleanup;
    }

    if (input_info.st_ino != 0 &&
        input_info.st_dev == output_info.st_dev &&
        input_info.st_ino == output_info.st_ino) {
        fprintf(stderr, "Error: file1 and file2 refer to the same file.\n");
        goto cleanup;
    }

    for (;;) {
        ssize_t bytes_read = read(input_fd, buffer, sizeof(buffer));

        if (bytes_read > 0) {
            if (write_all(output_fd, buffer, bytes_read) == -1) {
                perror("Error writing to file1");
                goto cleanup;
            }
        } else if (bytes_read == 0) {
            break;
        } else if (errno != EINTR) {
            perror("Error reading file2");
            goto cleanup;
        }
    }

    exit_status = EXIT_SUCCESS;

cleanup:
    if (input_fd != -1 && close(input_fd) == -1) {
        perror("Error closing file2");
        exit_status = EXIT_FAILURE;
    }

    if (output_fd != -1 && close(output_fd) == -1) {
        perror("Error closing file1");
        exit_status = EXIT_FAILURE;
    }

    return exit_status;
}

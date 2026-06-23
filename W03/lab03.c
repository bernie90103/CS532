/*
Lab Assignment #3 - Insertion Sort for Strings
Author: Bernie CHEN
Date: 06/15/26

Instructions to compile and run on CS Linux system:
1. Open terminal and navigate to the folder containing this file.
2. Compile the program using:
   gcc -Wall -Wextra -g lab03.c -o lab03
3. Run the program using:
   ./lab03
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1023

char **readStrings(int count);
void sortStrings(char **arr, int count);
void displayStrings(char **arr, int count);
void freeStrings(char **arr, int count);

int main(void) {
    int n;
    char **strings;

    printf("Please enter number of strings: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input\n");
        return 1;
    }

    strings = readStrings(n);
    if (strings == NULL) {
        return 1;
    }

    printf("Given strings are:\n");
    displayStrings(strings, n);

    sortStrings(strings, n);

    printf("Sorted strings are:\n");
    displayStrings(strings, n);

    freeStrings(strings, n);

    return 0;
}

char **readStrings(int count) {
    char **arr = (char **) calloc(count, sizeof(char *));

    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    for (int i = 0; i < count; i++) {
        char buffer[MAX_INPUT_LENGTH + 1];
        size_t length;

        printf("Please enter string %d: ", i + 1);
        if (scanf("%1023s", buffer) != 1) {
            printf("Invalid input\n");
            freeStrings(arr, count);
            return NULL;
        }

        length = strlen(buffer);
        arr[i] = (char *) malloc((length + 1) * sizeof(char));

        if (arr[i] == NULL) {
            printf("Memory allocation failed\n");
            freeStrings(arr, count);
            return NULL;
        }

        strcpy(arr[i], buffer);
    }

    return arr;
}

void sortStrings(char **arr, int count) {
    for (int i = 1; i < count; i++) {
        int curr_loc = i;

        while (curr_loc > 0 && strcmp(arr[curr_loc - 1], arr[curr_loc]) > 0) {
            char *temp = arr[curr_loc];
            arr[curr_loc] = arr[curr_loc - 1];
            arr[curr_loc - 1] = temp;
            curr_loc--;
        }
    }
}

void displayStrings(char **arr, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s\n", arr[i]);
    }
}

void freeStrings(char **arr, int count) {
    if (arr == NULL) {
        return;
    }

    for (int i = 0; i < count; i++) {
        free(arr[i]);
    }

    free(arr);
}

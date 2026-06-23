/*
Lab Assignment #2 - Insertion Sort
Author: Bernie CHEN
Date: 06/09/26

Instructions to compile and run on CS Linux system:
1. Open terminal and navigate to the folder containing this file.
2. Compile the program using:
   gcc -Wall -Wextra -g lab2.c -o lab2
3. Run the program using:
   ./lab2
*/
#include <stdio.h>

int main(void) {
    int n;

    printf("Please enter number of elements in array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input\n");
        return 1;
    }

    int arr[n];

    for (int i = 0; i < n; i++) {
        printf("Please enter element %d of array: ", i + 1);
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input\n");
            return 1;
        }
    }

    printf("Given array is: [");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    for (int i = 1; i < n; i++) {
        int curr_loc = i;

        while (curr_loc > 0 && arr[curr_loc - 1] > arr[curr_loc]) {
            int temp = arr[curr_loc];
            arr[curr_loc] = arr[curr_loc - 1];
            arr[curr_loc - 1] = temp;
            curr_loc--;
        }
    }

    printf("Sorted array is: [");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    return 0;
}

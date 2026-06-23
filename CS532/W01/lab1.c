/*
Lab Assignment #1 - Prime Number Checker
Author: PO YEN CHEN
Date: 06/02/26

Instructions to compile and run on CS Linux system:
1. Open terminal and navigate to the folder containing this file.
2. Compile the program using:
   gcc -o lab1 lab1.c
3. Run the program using:
   ./lab1
*/
/*
Result:
@bernie90103 ➜ /workspaces/CS532/CS532 (main) $ gcc -o lab1 lab1.c
@bernie90103 ➜ /workspaces/CS532/CS532 (main) $ ./lab1
Enter a number: 1
The number is not prime
@bernie90103 ➜ /workspaces/CS532/CS532 (main) $ ./lab1
Enter a number: 7
The number is prime
*/
#include <stdio.h>

int main(void) {
    int given_number;
    int is_prime = 1; // Assume the number is prime initially

    // Read integer input from user
    printf("Enter a number: ");
    if (scanf("%d", &given_number) != 1) {
        printf("Invalid input\n");
        return 1;
    }

    // Check if number is less than or equal to 1
    if (given_number <= 1) {
        is_prime = 0; // Numbers <= 1 are not prime
    } else {
        // Check for factors from 2 up to sqrt(given_number)
        for (int i = 2; i*i <= given_number; i++) {
            if (given_number % i == 0) {
                is_prime = 0; // Found a factor, not prime
                break;
            }
        }
    }

    // Output the result
    if (is_prime) {
        printf("The number is prime\n");
    } else {
        printf("The number is not prime\n");
    }

    return 0;
}

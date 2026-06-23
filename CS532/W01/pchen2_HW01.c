#include <stdio.h>
#include <stdlib.h>

int sumOfDigits(int n) {
    int sum = 0;

    if (n <= 0) return -1;

    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

int UABMaxMinDiff(int arr[], int size) {
    int max;
    int min;

    if (size <= 0) return -1;

    max = arr[0];
    min = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }

    return max - min;
}

int *replaceEvenWithZero(int arr[], int size) {
    int *newArr;

    if (size <= 0) return NULL;

    newArr = malloc(size * sizeof(int));
    if (newArr == NULL) return NULL;

    for (int i = 0; i < size; i++) {
        newArr[i] = (arr[i] % 2 == 0) ? 0 : arr[i];
    }

    return newArr;
}

int perfectSquare(int n) {
    int i = 0;

    if (n < 0) return 0;

    while (i * i < n) {
        i++;
    }

    return i * i == n;
}

int countVowels(char s[]) {
    int count = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];

        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            count++;
        }
    }

    return count;
}

void printArray(int arr[], int size) {
    printf("[");

    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }

    printf("]");
}

int main(void) {
    int arr1[] = {3, 7, 2, 9};
    int arr2[] = {5, 5, 5, 5, 5, 5};
    int arr3[] = {-2, 4, -1, 6, 5};
    int evenArr1[] = {1, 2, 3, 4};
    int evenArr2[] = {2, 4, 6};
    int evenArr3[] = {1, 3, 5};
    int *newArr1;
    int *newArr2;
    int *newArr3;

    /*
     * Problem 1: sumOfDigits
     */
    printf("sumOfDigits(123) = %d\n", sumOfDigits(123));
    printf("sumOfDigits(405) = %d\n", sumOfDigits(405));
    printf("sumOfDigits(0) = %d\n", sumOfDigits(0));
    printf("sumOfDigits(7) = %d\n", sumOfDigits(7));
    printf("sumOfDigits(-308) = %d\n\n", sumOfDigits(-308));

    /*
     * Problem 2: UABMaxMinDiff
     */
    printf("UABMaxMinDiff([3, 7, 2, 9]) = %d\n", UABMaxMinDiff(arr1, 4));
    printf("UABMaxMinDiff([5, 5, 5, 5, 5, 5]) = %d\n", UABMaxMinDiff(arr2, 6));
    printf("UABMaxMinDiff([-2, 4, -1, 6, 5]) = %d\n\n", UABMaxMinDiff(arr3, 5));

    /*
     * Problem 3: replaceEvenWithZero
     */
    newArr1 = replaceEvenWithZero(evenArr1, 4);
    newArr2 = replaceEvenWithZero(evenArr2, 3);
    newArr3 = replaceEvenWithZero(evenArr3, 3);

    printf("replaceEvenWithZero([1, 2, 3, 4]) = ");
    printArray(newArr1, 4);
    printf("\n");

    printf("replaceEvenWithZero([2, 4, 6]) = ");
    printArray(newArr2, 3);
    printf("\n");

    printf("replaceEvenWithZero([1, 3, 5]) = ");
    printArray(newArr3, 3);
    printf("\n\n");

    /*
     * Problem 4: perfectSquare
     */
    printf("perfectSquare(16) = %s\n", perfectSquare(16) ? "True" : "False");
    printf("perfectSquare(15) = %s\n", perfectSquare(15) ? "True" : "False");
    printf("perfectSquare(25) = %s\n", perfectSquare(25) ? "True" : "False");
    printf("perfectSquare(36) = %s\n\n", perfectSquare(36) ? "True" : "False");

    /*
     * Problem 5: countVowels
     */
    printf("countVowels(\"Hello World\") = %d\n", countVowels("Hello World"));
    printf("countVowels(\"UAB CS\") = %d\n", countVowels("UAB CS"));
    printf("countVowels(\"Python\") = %d\n", countVowels("Python"));
    printf("countVowels(\"aeiou\") = %d\n", countVowels("aeiou"));

    free(newArr1);
    free(newArr2);
    free(newArr3);

    return 0;
}

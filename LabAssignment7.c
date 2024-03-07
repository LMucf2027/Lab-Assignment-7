/*
Luke Mathew
Lab Assignment 7
COP 3502C
March 7th, 2024
*/
#include <stdio.h>

void bubbleSort(int arr[], int n, int swaps[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps[arr[j]]++;
                swaps[arr[j + 1]]++;
            }
        }
    }
}

void selectionSort(int arr[], int n, int swaps[]) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
        swaps[arr[min_idx]]++;
        swaps[arr[i]]++;
    }
}

int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n1 = sizeof(array1) / sizeof(array1[0]);
    int n2 = sizeof(array2) / sizeof(array2[0]);

    int swaps1[100] = {0}; // assuming values are less than 100
    int swaps2[100] = {0}; // assuming values are less than 100

    bubbleSort(array1, n1, swaps1);
    bubbleSort(array2, n2, swaps2);

    printf("array1:\n");
    for (int i = 0; i < n1; i++) {
        if (swaps1[array1[i]] > 0) {
            printf("%d: %d times swapped\n", array1[i], swaps1[array1[i]]);
        }
    }
    printf("Total swaps: %d\n", n1 * (n1 - 1) / 2);

    printf("\narray2:\n");
    for (int i = 0; i < n2; i++) {
        if (swaps2[array2[i]] > 0) {
            printf("%d: %d times swapped\n", array2[i], swaps2[array2[i]]);
        }
    }
    printf("Total swaps: %d\n", n2 * (n2 - 1) / 2);

    return 0;
}
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Function to swap two elements in an array
void swap(int *arr, int idx1, int idx2) {
    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

// Function to reverse a sequence in the array
void reverse(int *arr, int start, int end) {
    while (start < end) {
        swap(arr, start, end);
        start++;
        end--;
    }
}

// Function to calculate the next permutation
bool nextPermutation(int *arr, int size) {
    // Find the first element that is smaller than its successor
    int i = size - 2;
    while (i >= 0 && arr[i] >= arr[i + 1]) {
        i--;
    }

    // If i is less than 0, this is the largest possible permutation
    if (i < 0) {
        return false;
    }

    // Find the next larger element in the suffix
    int j = size - 1;
    while (arr[j] <= arr[i]) {
        j--;
    }

    // Swap the element i with the element j
    swap(arr, i, j);

    // Reverse the suffix to get the smallest next larger permutation
    reverse(arr, i + 1, size - 1);

    return true;
}

int main() {
    int size = 0;
    scanf("%d", &size);

    int* sequence = (int*)malloc(size * sizeof(int));
    printf(": ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &sequence[i]);
    }

    if (nextPermutation(sequence, size)) {
        printf(": \n");
        for (int i = 0; i < size; i++) {
            printf("%d ", sequence[i]);
        }
        printf("\n");
    } else {
        for (int i = size - 1; i >= 0; i--) {
            printf("%d ", sequence[i]);
        }
        printf("\n");
    }

    return 0;
}
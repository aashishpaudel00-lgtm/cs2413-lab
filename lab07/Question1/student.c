
#include <stdbool.h>

// Helper function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Basic Bubble Sort
void bubbleSort(int arr[], int size) {
    if (size <= 1) return;

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Optimized Bubble Sort (with early stopping)
void bubbleSortOptimized(int arr[], int size) {
    if (size <= 1) return;

    for (int i = 0; i < size - 1; i++) {
        bool swapped = false;

        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }

        // If no swaps happened, array is already sorted
        if (!swapped) {
            break;
        }
    }
}
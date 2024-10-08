#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    if (i == -1) {
        swap(&arr[low], &arr[high]);
        return low;
    } else {
        swap(&arr[i + 1], &arr[high]);
        return i + 1;
    }
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int loc = partition(arr, low, high);
        quicksort(arr, low, loc - 1);
        quicksort(arr, loc + 1, high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {5, 2, 9, 1, 7, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    quicksort(arr, 0, n - 1);
    printArray(arr, n);
    return 0;
}
#include <stdio.h>

int getMax(int arr[], int n) {
    int max = arr[0];
    for(int i = 1; i < n; i++)
        if(arr[i] > max)
            max = arr[i];
    return max;
}

void countingSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    for(int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for(int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for(int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for(int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int max = getMax(arr, n);
    for(int exp = 1; max / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

int main() {
    int arr[8] = {56, 36, 89, 57, 1, 0, 67, 59};
    int n = 8;

    radixSort(arr, n);

    printf("Array after Radix Sort (Ascending):\n");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}

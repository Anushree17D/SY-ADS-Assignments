#include <stdio.h>
int main() {
    int arr[8] = {56, 36, 89, 57, 1, 0, 67, 59};
    int n = 8, i, j, maxIndex, temp;

    for(i = 0; i < n - 1; i++) {
        maxIndex = i;
        for(j = i + 1; j < n; j++) {
            if(arr[j] > arr[maxIndex])  
        }

        temp = arr[i];
        arr[i] = arr[maxIndex];
        arr[maxIndex] = temp;
    }

    printf("Array after Selection Sort (Descending):\n");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}

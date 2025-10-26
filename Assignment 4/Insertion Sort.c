#include <stdio.h>
int main() {
    int arr[8] = {56, 36, 89, 57, 1, 0, 67, 59};
    int n = 8, i, j, key;

    for(i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    printf("Array after Insertion Sort (Ascending):\n");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}

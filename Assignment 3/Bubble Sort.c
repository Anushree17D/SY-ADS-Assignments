#include <stdio.h>
int main() {
    int arr[8] = {56, 36, 89, 57, 1, 0, 67, 59};
    int n = 8, i, j, temp;

    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {  
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Array after Bubble Sort (Ascending):\n");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}

#include <stdio.h>
int main() {
    int arr[10], i;
    printf("Enter 10 elements:\n");
    for(i = 0; i < 10; i++)
        scanf("%d", &arr[i]);

    for(i = 0; i < 10; i++) {
        if(i % 2 == 0)  
            arr[i] = arr[i] * arr[i];
    }

    printf("Updated array:\n");
    for(i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    return 0;
}

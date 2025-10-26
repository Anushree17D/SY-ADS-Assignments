#include <stdio.h>
int main() {
    int arr[] = {56, 36, 89, 57, 1, 0, 67, 59};
    int n = 8,key;

    printf("Enter number to search: ");
    scanf("%d", &key);

    for(i = 0; i < n; i++) {
        if(arr[i] == key) {
            printf("Element %d found at position %d\n", key, i + 1);
            return;;
        }
    }

    printf("Element %d not found in array.\n", key);

    return 0;
}

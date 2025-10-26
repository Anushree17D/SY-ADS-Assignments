#include <stdio.h>
int main() {
    int arr[] = {0, 1, 36, 56, 57, 59, 67, 89};
    int n = 8, key, low = 0, high = n - 1, mid, found = 0;

    printf("Enter number to search: ");
    scanf("%d", &key);

    while(low <= high) {
        mid = (low + high) / 2;

        if(arr[mid] == key) {
            printf("Element %d found at position %d\n", key, mid + 1);
            found = 1;
            break;
        }
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    if(!found)
        printf("Element %d not found in array.\n", key);

    return 0;
}

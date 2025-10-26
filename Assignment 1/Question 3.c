#include <stdio.h>
int main() {
    int arr[10], i, j, key = 0;
    printf("Enter 10 elements:\n");
    for(i = 0; i < 10; i++)
        scanf("%d", &arr[i]);

    for(i = 0; i < 10; i++) {
        for(j = i + 1; j < 10; j++) {
            if(arr[i] == arr[j]) {
                printf("First Repeating Element: %d", arr[i]);
                key = 1;
                break;
            }
        }
        if(key) break;
    }

    if(!key) printf("No repeating elements found.");
    return 0;
}

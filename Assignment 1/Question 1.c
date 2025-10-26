#include <stdio.h>

int main() {
    
    int numbers[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int n1 = 10;
    int sum = 0; 

    printf("--- i. Average of 10 Numbers ---\n");
    for (int i = 0; i < n1; i++) {
        sum += numbers[i];
    }
    double average = (double)sum / n1;
    printf("The sum of the array elements is: %d\n", sum);
    printf("The average of the 10 numbers is: %.2f\n\n", average);

    return 0;
}

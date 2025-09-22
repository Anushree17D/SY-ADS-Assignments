#include <stdio.h>
#define MAX 5 

int stack[MAX], top = -1;

int isEmpty() {
    return (top == -1);
}

int isFull() {
    return (top == MAX - 1);
}

void push(int value) {
    if (isFull()) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        stack[++top] = value;
        printf("%d pushed into stack\n", value);
    }
}

void pop() {
    if (isEmpty()) {
        printf("Stack Underflow! Cannot pop\n");
    } else {
        printf("%d popped from stack\n", stack[top--]);
    }
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    do {
        printf("\n--- Stack Operations ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Is Empty\n");
        printf("4. Is Full\n");
        printf("5. Display\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                if (isEmpty())
                    printf("Stack is EMPTY!\n");
                else
                    printf("Stack is NOT empty!\n");
                break;
            case 4:
                if (isFull())
                    printf("Stack is FULL!\n");
                else
                    printf("Stack is NOT full!\n");
                break;
            case 5:
                display();
                break;
            case 0:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 0);

    return 0;
}

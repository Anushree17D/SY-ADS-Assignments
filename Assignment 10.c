#include <stdio.h>
#define MAX 10

int queue[MAX];
int front = -1;
int rear = -1;

void insert(int num){
    if((front == 0 && rear == MAX-1) || (front == rear+1) ){
        printf("OVERFLOW\n");
        return;
    }

    if(front == -1 && rear == -1){
        front = rear = 0;
    }else if(rear == MAX-1 && front != 0){
        rear = 0;
    }else{
        rear++;
    }
    queue[rear] = num;

    printf("%d inserted into queue.\n", num);
}

void delete(){
    if (front == -1 && rear == -1){
        printf("UNDERFLOW!\n");
        return;
    }
    
    int val = queue[front];
    printf("Deleted element: %d\n", val);

    if(front == rear){
        front = rear = -1;
    }else{
        if(front == MAX-1){
            front = 0;
        }else{
            front++;
        }
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements are: ");

    if (rear >= front) {
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    } else {
        for (int i = front; i < MAX; i++) {
            printf("%d ", queue[i]);
        }
        for (int i = 0; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }

    printf("\n");
}

int main() {
    int choice, num;

    while(1){
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &num);
                insert(num);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

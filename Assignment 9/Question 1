#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int num){
    if (rear == MAX - 1){
        printf("Overflow!");
        return;
    }

    if (front == -1 && rear == -1){
        front = rear = 0;
    }else{
        rear++;
    }
    queue[rear] = num;

    printf("%d inserted into queue.\n", num);
}

void dequeue(){
    if (front == -1){
        printf("Underflow\n");
        return;
    }

    int last = queue[front];
    front++;

    if (front > rear){
        front = rear = -1;
    }

    printf("%d deleted from queue.\n", last);
}

void display(){
    if (front == -1 && rear == -1){
        printf("Queue Empty");
        return;
    }

    printf("Current Queue:- \n");
    for (int i = front; i <= rear; i++){
        printf("%d ", queue[i]);
    }
    printf("\n");
}

void peek(){
    if (front == -1 && rear == -1){
        printf("Queue Empty");
        return;
    }

    int val = queue[front];
    printf ("Peeked and found element: %d\n",val);
}

int main(){
    int choice, element;
    printf("---Primitive Operations on Queue---\n");

    while (1){
        printf ("-----------------------------------------------\n");
        printf("1. Insert or Enqueue\n");
        printf("2. Delete or Dequeue\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                printf("Enter the element to be inserted:\n");
                scanf("%d", &element);
                enqueue(element);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
            peek();
            break;

            case 5:
            return 0;
        }
    }
}

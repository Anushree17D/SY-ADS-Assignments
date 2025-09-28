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

int main(){
    enqueue(10);
    enqueue(50);
    dequeue();
    enqueue(100);
    enqueue(20);
    dequeue();
    enqueue(25);
    enqueue(200);
    display();
}

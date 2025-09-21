#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void create (int num){
    
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(head != NULL){
        printf ("List already exits...Please try other options for inserting nodes.\n");
        return;
    }
    newNode->data = num;
    newNode->next = NULL;
    head = newNode;

    printf ("List created with %d as first node.",num);
}

void display(){
    struct Node* temp = head;
    printf ("Current List :-\n");
    if(temp==NULL){
        printf ("List is empty.\n");
        return;
    }
    while(temp != NULL){
        printf ("%d -> ", temp->data);
        temp = temp->next;
    }
    printf ("NULL\n");
}

void insertAtStart (int num){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = num;
    newNode->next = head;
    head = newNode;

    printf ("%d inserted as new node at the beginning.n",num);
}

void insertAtEnd (int num){
    
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = num;
    newNode->next = NULL;

    if (head==NULL){
        head = newNode;
    }else{
        struct Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    
    printf ("%d inserted as new node at the end.\n",num);
}

int count(){
    int count = 0;
    struct Node* temp = head;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }

    return count;
}

void insertAtPosition(int num, int pos){
    int len = count();

    if (pos < 1 || pos > len+1){
        printf ("Invalid Input!");
        return;
    }

    if(pos == 1){
        insertAtStart(num);
        return;
    }

    if(pos == len+1){
        insertAtEnd(num);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = num;

    struct Node* temp = head;
    for(int i = 1 ; i < pos-1 ; i++){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;

    printf ("%d inserted at %d position.\n",num , pos);
}

void deleteFirst(){
    if (head==NULL){
        printf ("List is empty.");
        return;
    }

    struct Node* temp = head;
    head = head->next;
    free(temp);
    printf ("First node deleted.\n");
}

void deleteLast(){
    if (head==NULL){
        printf ("List is empty.");
        return;
    }
    if(head->next ==NULL){
        free(head);
        head = NULL;
        return;
    }

    struct Node* temp = head;
    while (temp->next->next != NULL){
        temp = temp->next;
    }
    struct Node* last = temp->next;
    temp->next=NULL;
    free(last); 
}

void search (int target){
    struct Node* temp = head;
    int pos = 1;
    int found = 0;

    while(temp != NULL){
        if(temp->data == target){
            printf ("%d found at node %d\n ", target , pos);
            found = 1;
            break;
        }
        temp = temp->next;
        pos++;
    }

    if(!found){
        printf ("%d not found in list\n", target);
    }
    
}

void deletePosition(int pos){
    if (head == NULL){
        printf ("List is empty.\n");
        return;
    }

    int len = count();

    if (pos < 1 || pos > len){
        printf ("Invalid Position.\n");
        return;
    }

    if (pos == 1){
        deleteFirst();
        return;
    }

    if(pos == len){
        deleteLast();
        return;
    }

    struct Node* temp = head;
    for (int i = 1; i < pos-1; i++){
        temp = temp ->next;
    }
    
    struct Node* del = temp->next;
    temp->next = del->next;
    free(del);

    printf ("Node at position %d deleted.", pos);
    
}

 
int main() {
    printf ("---SINGLY LINKED LIST---\n");
    int choice,val,pos,nodes;

    while(1){
        printf ("\n");
        printf ("\n----------------------------------------------------------\n");
        printf ("1. Create\n");
        printf ("2. Display\n");
        printf ("3. Insert at beginning\n");
        printf ("4. Insert at position\n");
        printf ("5. Insert at End\n");
        printf ("6. Delete first node\n");
        printf ("7. Delete node at position\n");
        printf ("8. Delete last node\n");
        printf ("9. Count the number of nodes\n");
        printf ("10. Searching for a node\n");
        printf ("11. Exit\n");
        printf ("----------------------------------------------------------\n");
        printf ("Enter your choice: ");
        scanf ("%d", &choice);

        switch(choice){
            case 1: 
            printf ("Enter the value to make your first node in a new linked list: ");
            scanf ("%d", &val);
            create(val);
            break;

            case 2:
            display();
            break;

            case 3: 
            printf ("Enter the value to be inserted as the first node: ");
            scanf ("%d", &val);
            insertAtStart(val);
            break;

            case 4: 
            printf ("Enter the position to insert the new node at: ");
            scanf ("%d", &pos);
            printf ("Enter the value to inserted at this position: ");
            scanf ("%d", &val);
            insertAtPosition(val,pos);
            break;

            case 5:
            printf ("Enter the number to insert at the last node: ");
            scanf ("%d", &val);
            insertAtEnd(val);
            break;

            case 6:
            deleteFirst();
            break;

            case 7:
            printf ("Enter the position to delete node at: ");
            scanf ("%d", &pos);
            deletePosition(pos);
            break;

            case 8:
            deleteLast();
            break;

            case 9: 
            nodes = count();
            printf ("The current number of nodes is: %d\n ",nodes );
            break;

            case 10:
            printf ("Enter the target data: ");
            scanf ("%d", &val);
            search(val);
            break;  

            case 11:
            printf ("Exiting...\n");
            return 0;

            default:
            printf ("Invalid Choice.");
            break;

        }
    }
}

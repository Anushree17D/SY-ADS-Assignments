#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Head pointer to the list
struct Node* head = NULL;

// Function to create the list by adding nodes at the end
void create(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    printf("Node created with value %d \n", value);
}

// Insert at the beginning
void insertAtBeginning(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    printf("Node inserted at beginning with value %d \n", value);
}

// Insert at the end
void insertAtEnd(int value) {
    create(value);
}

// Insert at middle (after a given position)
void insertAtMiddle(int value, int position) {
    if (position < 1) {
        printf("Invalid position! \n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (position == 1) {
        newNode->next = head;
        head = newNode;
        printf("Node inserted at position %d \n", position);
        return;
    }

    struct Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of bounds! \n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    printf("Node inserted at position %d with value %d \n", position, value);
}

// Delete the first node
void deleteFirst() {
    if (head == NULL) {
        printf("List is empty! \n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    printf("Deleted node with value %d from beginning \n", temp->data);
    free(temp);
}

// Delete at the end
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty! \n");
        return;
    }
    if (head->next == NULL) {
        printf("Deleted node with value %d from end \n", head->data);
        free(head);
        head = NULL;
        return;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    printf("Deleted node with value %d from end \n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
}

// Delete at middle (specific position)
void deleteMiddle(int position) {
    if (head == NULL) {
        printf("List is empty! \n");
        return;
    }
    if (position < 1) {
        printf("Invalid position! \n");
        return;
    }
    if (position == 1) {
        deleteFirst();
        return;
    }
    struct Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of bounds! \n");
        return;
    }

    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    printf("Deleted node with value %d at position %d \n", nodeToDelete->data, position);
    free(nodeToDelete);
}

// Count the nodes
void countNodes() {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("Total number of nodes: %d \n", count);
}

// Search for a node by value
void searchNode(int value) {
    int position = 1;
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == value) {
            printf("Node with value %d found at position %d \n", value, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Node with value %d not found \n", value);
}

// Display the list
void displayList() {
    if (head == NULL) {
        printf("List is empty! \n");
        return;
    }
    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL \n");
}

// Main menu
int main() {
    int choice, value, position;

    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("\n-------------------------------\n");
        printf("1. Create node at end\n");
        printf("2. Insert at beginning\n");
        printf("3. Insert at middle\n");
        printf("4. Insert at end\n");
        printf("5. Delete first node\n");
        printf("6. Delete at middle\n");
        printf("7. Delete at end\n");
        printf("8. Count nodes\n");
        printf("9. Search node\n");
        printf("10. Display list\n");
        printf("0. Exit\n");
        printf("\n-------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to create node: ");
                scanf("%d", &value);
                create(value);
                break;
            case 2:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position to insert at: ");
                scanf("%d", &position);
                insertAtMiddle(value, position);
                break;
            case 4:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 5:
                deleteFirst();
                break;
            case 6:
                printf("Enter position to delete at: ");
                scanf("%d", &position);
                deleteMiddle(position);
                break;
            case 7:
                deleteEnd();
                break;
            case 8:
                countNodes();
                break;
            case 9:
                printf("Enter value to search: ");
                scanf("%d", &value);
                searchNode(value);
                break;
            case 10:
                displayList();
                break;
            case 0:
                printf("Exiting program \n");
                exit(0);
            default:
                printf("Invalid choice! \n");
        }
    }

    return 0;
}

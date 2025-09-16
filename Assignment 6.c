#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Create list by adding nodes at the end
void create() {
    int n, data;
    printf("Enter number of nodes to create: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        struct Node* newNode = createNode(data);

        if (head == NULL) {
            head = newNode;
        } else {
            struct Node* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
    printf("List created successfully!\n");
}

// Display the list
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Insert node at any position
void insert() {
    int pos, data;
    printf("Enter position to insert (1-based index): ");
    scanf("%d", &pos);
    printf("Enter data: ");
    scanf("%d", &data);

    struct Node* newNode = createNode(data);

    if (pos == 1) {
        newNode->next = head;
        if (head != NULL)
            head->prev = newNode;
        head = newNode;
        printf("Node inserted at position %d.\n", pos);
        return;
    }

    struct Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;
    printf("Node inserted at position %d.\n", pos);
}

// Delete node at any position
void deleteNode() {
    int pos;
    printf("Enter position to delete (1-based index): ");
    scanf("%d", &pos);

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;

    if (pos == 1) {
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        free(temp);
        printf("Node at position %d deleted.\n", pos);
        return;
    }

    for (int i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position!\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    free(temp);
    printf("Node at position %d deleted.\n", pos);
}

// Search for a node
void search() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    int key, pos = 1;
    printf("Enter the data to search: ");
    scanf("%d", &key);

    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Data %d found at position %d.\n", key, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Data %d not found in the list.\n", key);
}

// Count the number of nodes
void countNodes() {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("Total nodes in the list: %d\n", count);
}

// Main menu
int main() {
    int choice;
    do {
        printf("\n--- Doubly Linked List Operations ---\n");
        printf("1. Create list\n");
        printf("2. Display list\n");
        printf("3. Insert a node\n");
        printf("4. Delete a node\n");
        printf("5. Search for a node\n");
        printf("6. Count nodes\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insert(); break;
            case 4: deleteNode(); break;
            case 5: search(); break;
            case 6: countNodes(); break;
            case 7: printf("Exiting program.\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 7);

    return 0;
}

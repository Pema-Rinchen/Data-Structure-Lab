#include <stdio.h>
#include <stdlib.h>

// Define a structure for a singly linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at a given position in the list
struct Node* insertAtPosition(struct Node* head, int newData, int position) {
    if (position < 1) {
        printf("Invalid position.\n");
        return head;
    }

    struct Node* newNode = createNode(newData);

    // Insert at the beginning if the position is 1
    if (position == 1) {
        newNode->next = head;
        return newNode;
    }

    struct Node* current = head;
    int count = 1;

    // Traverse to the node just before the desired position
    while (current != NULL && count < position - 1) {
        current = current->next;
        count++;
    }

    if (current == NULL) {
        printf("Invalid position.\n");
        return head;
    }

    // Update the pointers to insert the new node
    newNode->next = current->next;
    current->next = newNode;

    return head;
}

// Function to print the singly linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Insert nodes at the beginning
    head = insertAtPosition(head, 1, 1);
    head = insertAtPosition(head, 3, 2);
    head = insertAtPosition(head, 2, 2);

    // Print the linked list
    printf("Linked List: ");
    printList(head);

    return 0;
}

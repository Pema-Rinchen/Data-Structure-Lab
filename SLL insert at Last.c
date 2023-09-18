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

// Function to insert a node at the end of the list
struct Node* insertAtEnd(struct Node* head, int newData) {
    struct Node* newNode = createNode(newData);

    // If the list is empty, the new node becomes the head
    if (head == NULL) {
        return newNode;
    }

    struct Node* current = head;

    // Traverse to the current last node
    while (current->next != NULL) {
        current = current->next;
    }

    // Update the pointers to insert the new node at the end
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

    // Insert nodes at the end
    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 3);

    // Print the linked list
    printf("Linked List: ");
    printList(head);

    return 0;
}

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

// Function to delete the first node of the list
struct Node* deleteFirstNode(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL; // Nothing to delete
    }

    // Create a temporary pointer to the first node
    struct Node* temp = head;

    // Update the head pointer to the second node
    head = head->next;

    // Free the memory occupied by the old first node
    free(temp);

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
    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 3);

    // Print the original linked list
    printf("Original Linked List: ");
    printList(head);

    // Delete the first node
    head = deleteFirstNode(head);

    // Print the updated linked list
    printf("Updated Linked List (after deleting the first node): ");
    printList(head);

    return 0;
}

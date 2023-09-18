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

// Function to delete the last node of the list
struct Node* deleteLastNode(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL; // Nothing to delete
    }

    // If there's only one node in the list
    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct Node* current = head;

    // Traverse to the second-to-last node
    while (current->next->next != NULL) {
        current = current->next;
    }

    // Free the memory occupied by the last node
    free(current->next);

    // Update the second-to-last node's next pointer to NULL
    current->next = NULL;

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
    head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);

    // Print the original linked list
    printf("Original Linked List: ");
    printList(head);

    // Delete the last node
    head = deleteLastNode(head);

    // Print the updated linked list
    printf("Updated Linked List (after deleting the last node): ");
    printList(head);

    return 0;
}

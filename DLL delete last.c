#include <stdio.h>
#include <stdlib.h>

// Define a structure for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to delete the last node
struct Node* deleteLastNode(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }

    // If there is only one node in the list
    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    // Traverse to the last node
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    // Update the pointers of the second-to-last node
    current->prev->next = NULL;

    // Free the memory occupied by the last node
    free(current);

    return head;
}

// Function to print the doubly linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Example: Create a doubly linked list
    for (int i = 1; i <= 5; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = i;
        newNode->prev = NULL;
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
    }

    printf("Original list: ");
    printList(head);

    // Delete the last node
    head = deleteLastNode(head);

    printf("Updated list: ");
    printList(head);

    return 0;
}

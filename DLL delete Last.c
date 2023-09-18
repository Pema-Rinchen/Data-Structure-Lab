#include <stdio.h>
#include <stdlib.h>

// Define a structure for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to delete the first node
struct Node* deleteFirstNode(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }

    // Store a reference to the new head
    struct Node* newHead = head->next;

    // If the list has more than one node
    if (newHead != NULL) {
        newHead->prev = NULL;
    }

    // Free the memory occupied by the original first node
    free(head);

    return newHead;
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

    // Delete the first node
    head = deleteFirstNode(head);

    printf("Updated list: ");
    printList(head);

    return 0;
}

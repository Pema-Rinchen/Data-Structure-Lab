#include <stdio.h>
#include <stdlib.h>

// Define a structure for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to delete a node at a given position
struct Node* deleteNodeAtPos(struct Node* head, int position) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }

    struct Node* current = head;
    int count = 1;

    // Traverse to the node at the given position
    while (current != NULL && count < position) {
        current = current->next;
        count++;
    }

    if (current == NULL) {
        printf("Invalid position.\n");
        return head;
    }

    // Update the pointers of the previous and next nodes
    if (current->prev != NULL) {
        current->prev->next = current->next;
    }
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    // If the node to be deleted is the head, update the head pointer
    if (count == 1) {
        head = current->next;
    }

    // Free the memory occupied by the deleted node
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

    int position;
    printf("Enter the position to delete: ");
    scanf("%d", &position);

    // Delete the node at the given position
    head = deleteNodeAtPos(head, position);

    printf("Updated list: ");
    printList(head);

    return 0;
}

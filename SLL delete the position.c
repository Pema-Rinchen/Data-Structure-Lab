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

// Function to delete a node from a specified position in the list
struct Node* deleteAtPosition(struct Node* head, int position) {
    if (head == NULL || position < 1) {
        printf("Invalid position or list is empty.\n");
        return head;
    }

    // If deleting the first node (position == 1)
    if (position == 1) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* current = head;
    int count = 1;

    // Traverse to the node just before the specified position
    while (current != NULL && count < position - 1) {
        current = current->next;
        count++;
    }

    // Check if the position is valid
    if (current == NULL || current->next == NULL) {
        printf("Invalid position.\n");
        return head;
    }

    // Update the pointers to delete the node at the specified position
    struct Node* temp = current->next;
    current->next = temp->next;
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
    head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);

    // Print the original linked list
    printf("Original Linked List: ");
    printList(head);

    // Delete a node from a specified position
    int position;
    printf("Enter the position to delete: ");
    scanf("%d", &position);
    head = deleteAtPosition(head, position);

    // Print the updated linked list
    printf("Updated Linked List: ");
    printList(head);

    return 0;
}

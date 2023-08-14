#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};

// create a new node 
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// function to inserte an link 
void insert(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

//display in asscending order
void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Display in reverse order
void displayReverse(struct Node* head) {
    if (head == NULL) {
        return;
    }
    displayReverse(head->next);
    printf("%d ", head->data);
}

//main function
int main() {
    struct Node* head = NULL;
    insert(&head, 12);
    insert(&head, 22);
    insert(&head, 30);
    insert(&head, 40);
    insert(&head, 44);
    insert(&head, 50);
    printf("Linked List in asscending order:\n");
    display(head);
    printf("\n");
    printf("Linked List in revesre order:\n");
    displayReverse(head);
    return 0;
}

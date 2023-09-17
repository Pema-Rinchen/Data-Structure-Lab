#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* addToBeginning(struct Node* head, int data) {
     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (head == NULL) {
        return newNode;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;

    return head;
}


int main() {
    struct Node* head = NULL;
    int array[5] = {5, 4, 3, 2, 1};

    for (int i = 0; i < 5; i++) {
        head = addToBeginning(head, array[i]);
    }

    printf("Double-Linked List: ");
     struct Node* current = head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    return 0;
}

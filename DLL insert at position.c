#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* addToEnd(struct Node* head, int data) {
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

struct Node* insertInMiddle(struct Node* head, int data, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (position <= 0) {
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        return newNode;
    }

    struct Node* current = head;
    while (position > 1 && current != NULL) {
        current = current->next;
        position--;
    }

    if (current == NULL) {
        return addToEnd(head, data);
    } else {
        newNode->prev = current;
        newNode->next = current->next;
        if (current->next != NULL) {
            current->next->prev = newNode;
        }
        current->next = newNode;
    }

    return head;
}
int main() {
    struct Node* head = NULL;
    int array[5] = {5, 4, 3, 2, 1};

    for (int i = 0; i < 5; i++) {
        head = addToEnd(head, array[i]);
    }
    head=insertInMiddle(head,6,3);
    printf("Double-Linked List: ");
     struct Node* current = head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    return 0;
}

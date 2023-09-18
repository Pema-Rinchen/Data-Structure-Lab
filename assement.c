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
    } else {
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }
}
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
    head=addToEnd(head,35);
    head=addToEnd(head,46);
    head=addToEnd(head,95);
    printf("orginal DLL ");
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("\NULL\n");
    
    head=addToBeginning(head,29);
    head=addToEnd(head,45);
    head=insertInMiddle(head,24,2);
    printf("after data three data  ");
    struct Node* ptr = head;
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("\NULL");
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;

void enqueue(int data) {
    struct node* ptr = malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;
    if (front == NULL && rear == NULL) {
        front = rear = ptr;
    } else {
        rear->next = ptr;
        rear = ptr;
    }
    printf("Node added\n");
}

int dequeue() {
    if (front == NULL) {
        printf("Underflow\n");
        return -1;
    } else {
        struct node* temp = front;
        int temp_data = front->data;
        front = front->next;
        free(temp);
        return temp_data;
    }
}

void display() {
    if (front == NULL) {
        printf("Underflow\n");
        return;
    } else {
        struct node* temp = front;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("null\n");
    }
}

int main() {
    int choice, data;
    choice = 0; // Initialize choice
    while (choice != 4) {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                printf("Popped element: %d\n", dequeue());
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting the program\n");
                break;
            default:
                printf("Wrong choice\n");
                break;
        }
    }
    return 0; // Indicate successful program execution
}

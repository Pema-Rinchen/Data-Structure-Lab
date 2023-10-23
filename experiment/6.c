#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct DoublyLinkedList {
    struct Node* head;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void display(struct DoublyLinkedList* list) {
    struct Node* current = list->head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void create(struct DoublyLinkedList* list) {
    int n, data;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        struct Node* newNode = createNode(data);

        if (list->head == NULL) {
            list->head = newNode;
        } else {
            struct Node* current = list->head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }
    }
}

void insert(struct DoublyLinkedList* list) {
    int data, position;
    printf("Enter the element to insert: ");
    scanf("%d", &data);
    printf("Enter the position to insert (0-based index): ");
    scanf("%d", &position);

    struct Node* newNode = createNode(data);
    if (position == 0) {
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    } else {
        struct Node* current = list->head;
        int i = 0;

        while (i < position - 1 && current->next != NULL) {
            current = current->next;
            i++;
        }

        if (current->next == NULL) {
            current->next = newNode;
            newNode->prev = current;
        } else {
            newNode->next = current->next;
            newNode->next->prev = newNode;
            current->next = newNode;
            newNode->prev = current;
        }
    }
}

void deleteNode(struct DoublyLinkedList* list) {
    if (list->head == NULL) {
        printf("Doubly linked list is empty. Cannot delete.\n");
        return;
    }

    int data;
    printf("Enter the element to delete: ");
    scanf("%d", &data);

    struct Node* current = list->head;

    while (current != NULL) {
        if (current->data == data) {
            if (current->prev == NULL) {
                list->head = current->next;
            } else {
                current->prev->next = current->next;
            }

            if (current->next != NULL) {
                current->next->prev = current->prev;
            }

            free(current);
            printf("Deleted %d from the doubly linked list.\n");
            return;
        }

        current = current->next;
    }

    printf("%d not found in the doubly linked list.\n", data);
}

void reverse(struct DoublyLinkedList* list) {
    struct Node* current = list->head;
    struct Node* temp = NULL;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL) {
        list->head = temp->prev;
    }
}

void concatenate(struct DoublyLinkedList* list1, struct DoublyLinkedList* list2) {
    if (list1->head == NULL) {
        list1->head = list2->head;
    } else if (list2->head != NULL) {
        struct Node* current = list1->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = list2->head;
        list2->head->prev = current;
    }
}

int main() {
    struct DoublyLinkedList list;
    list.head = NULL;

    int choice;
    struct DoublyLinkedList list2;
    list2.head = NULL;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Reverse\n");
        printf("5. Concatenate\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create(&list);
                break;
            case 2:
                insert(&list);
                break;
            case 3:
                deleteNode(&list);
                break;
            case 4:
                reverse(&list);
                break;
            case 5:
                create(&list2);
                concatenate(&list, &list2);
                break;
            case 6:
                display(&list);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}


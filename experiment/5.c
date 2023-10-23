#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct CircularLinkedList {
    struct Node* head;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void display(struct CircularLinkedList* list) {
    if (list->head == NULL) {
        printf("Circular linked list is empty.\n");
        return;
    }

    struct Node* current = list->head;

    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != list->head);

    printf("... (circular)\n");
}

void create(struct CircularLinkedList* list) {
    int n, data;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        struct Node* newNode = createNode(data);

        if (list->head == NULL) {
            list->head = newNode;
            newNode->next = list->head;
        } else {
            struct Node* current = list->head;
            while (current->next != list->head) {
                current = current->next;
            }
            current->next = newNode;
            newNode->next = list->head;
        }
    }
}

void insert(struct CircularLinkedList* list) {
    if (list->head == NULL) {
        printf("Circular linked list is empty. Cannot insert.\n");
        return;
    }

    int data, position;
    printf("Enter the element to insert: ");
    scanf("%d", &data);
    printf("Enter the position to insert (0-based index): ");
    scanf("%d", &position);

    struct Node* newNode = createNode(data);

    if (position == 0) {
        newNode->next = list->head;
        struct Node* current = list->head;

        while (current->next != list->head) {
            current = current->next;
        }

        current->next = newNode;
        list->head = newNode;
    } else {
        struct Node* current = list->head;
        int i = 0;

        while (i < position - 1) {
            current = current->next;
            i++;

            if (current == list->head) {
                printf("Invalid position.\n");
                return;
            }
        }

        newNode->next = current->next;
        current->next = newNode;
    }
}

void deleteNode(struct CircularLinkedList* list) {
    if (list->head == NULL) {
        printf("Circular linked list is empty. Cannot delete.\n");
        return;
    }

    int data;
    printf("Enter the element to delete: ");
    scanf("%d", &data);

    struct Node* current = list->head;
    struct Node* prev = NULL;

    while (1) {
        if (current->data == data) {
            if (current == list->head) {
                struct Node* last = list->head;

                while (last->next != list->head) {
                    last = last->next;
                }

                last->next = list->head->next;
                list->head = list->head->next;
            }

            prev->next = current->next;
            free(current);
            printf("Deleted %d from the circular linked list.\n");
            return;
        }

        prev = current;
        current = current->next;

        if (current == list->head) {
            printf("%d not found in the circular linked list.\n", data);
            return;
        }
    }
}

void reverse(struct CircularLinkedList* list) {
    if (list->head == NULL) {
        printf("Circular linked list is empty. Cannot reverse.\n");
        return;
    }

    struct Node* current = list->head;
    struct Node *prev = NULL, *next = NULL;

    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != list->head);

    list->head->next = prev;
    list->head = prev;
}

void concatenate(struct CircularLinkedList* list1, struct CircularLinkedList* list2) {
    if (list2->head == NULL) {
        printf("Second circular linked list is empty. Cannot concatenate.\n");
        return;
    }

    if (list1->head == NULL) {
        list1->head = list2->head;
    } else {
        struct Node* current = list1->head;

        while (current->next != list1->head) {
            current = current->next;
        }

        current->next = list2->head;

        current = list2->head;
        while (current->next != list2->head) {
            current = current->next;
        }

        current->next = list1->head;
    }
}

int main() {
    struct CircularLinkedList list;
    list.head = NULL;
    int choice;
    struct CircularLinkedList list2;
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


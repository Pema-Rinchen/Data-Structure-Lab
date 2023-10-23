#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct LinkedList {
    struct Node* head;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void display(struct LinkedList* list) {
    struct Node* current = list->head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void create(struct LinkedList* list) {
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
        }
    }
}

void insert(struct LinkedList* list) {
    int data, position;
    printf("Enter the element to insert: ");
    scanf("%d", &data);
    printf("Enter the position to insert (0-based index): ");
    scanf("%d", &position);

    struct Node* newNode = createNode(data);
    if (position == 0) {
        newNode->next = list->head;
        list->head = newNode;
    } else {
        struct Node* current = list->head;
        for (int i = 0; i < position - 1 && current != NULL; i++) {
            current = current->next;
        }
        if (current == NULL) {
            printf("Invalid position.\n");
            return;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void deleteNode(struct LinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty.\n");
        return;
    }

    int data;
    printf("Enter the element to delete: ");
    scanf("%d", &data);

    struct Node* current = list->head;
    if (current->data == data) {
        list->head = current->next;
        free(current);
        return;
    }

    while (current->next != NULL) {
        if (current->next->data == data) {
            struct Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
            return;
        }
        current = current->next;
    }

    printf("%d not found in the list.\n", data);
}

void reverse(struct LinkedList* list) {
    struct Node* prev = NULL;
    struct Node* current = list->head;
    struct Node* next;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    list->head = prev;
}

void concatenate(struct LinkedList* list1, struct LinkedList* list2) {
    if (list1->head == NULL) {
        list1->head = list2->head;
    } else {
        struct Node* current = list1->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = list2->head;
    }
}

int main() {
    struct LinkedList list;
    list.head = NULL;

    int choice;
    struct LinkedList list2;
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

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to perform in-order traversal
void inOrder(struct Node *root) {
    if (root == NULL)
        return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

// Function to insert a node into a BST
struct Node *insert(struct Node *root, int data) {
    if (root == NULL)
        return createNode(data);
    
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

// Function to find the minimum value node in a BST
struct Node *minValueNode(struct Node *node) {
    struct Node *current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

// Function to delete a node in a BST
struct Node *deleteNode(struct Node *root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the in-order successor (smallest in the right subtree)
        struct Node *temp = minValueNode(root->right);

        // Copy the in-order successor's content to this node
        root->data = temp->data;

        // Delete the in-order successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    struct Node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("In-order traversal before deletion: ");
    inOrder(root);
    printf("\n");

    int key_to_delete = 30;
    root = deleteNode(root, key_to_delete);

    printf("In-order traversal after deletion of %d: ", key_to_delete);
    inOrder(root);
    printf("\n");

    return 0;
}

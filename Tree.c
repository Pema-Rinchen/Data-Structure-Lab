#include <stdio.h>
#include <stdlib.h>

struct bt{
    int data;
    struct bt *left;
    struct bt *right;
};

struct bt *create(int data){
    struct bt *newnode = malloc(sizeof(struct bt));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct bt* insert(struct bt* root, int data) {
    if (root == NULL) {
        return create(data);
    }
    
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    
    return root;
}

void preorder(struct bt *root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct bt *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void postorder(struct bt *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

int main(){
    int num;
    struct bt *root = NULL;
    
    // Example array of data
    int data_array[] = {10, 5, 15, 3, 7, 12, 18};
    num = sizeof(data_array) / sizeof(data_array[0]);
    
    for (int i = 0; i < num; i++) {
        root = insert(root, data_array[i]); // Insert data from the array into the tree
    }
    
    printf("Binary Search Tree Traversals:\n");
    
    printf("\nPreorder traversal: ");
    preorder(root);

    printf("\nInorder traversal: ");
    inorder(root);

    printf("\nPostorder traversal: ");
    postorder(root);

    printf("\n");
    
    return 0;
}

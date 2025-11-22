#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};


struct node* newNode(int value) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert(struct node* root, int value) {
    if (root == NULL)
        return newNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}


struct node* searchRecursive(struct node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return searchRecursive(root->left, key);
    else
        return searchRecursive(root->right, key);
}


struct node* searchNonRecursive(struct node* root, int key) {
    while (root != NULL) {
        if (key == root->data)
            return root;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}


struct node* findMin(struct node* root) {
    if (root == NULL) return NULL;

    while (root->left != NULL)
        root = root->left;

    return root;
}


struct node* findMax(struct node* root) {
    if (root == NULL) return NULL;

    while (root->right != NULL)
        root = root->right;

    return root;
}


struct node* inorderSuccessor(struct node* root, int key) {
    struct node* curr = searchNonRecursive(root, key);
    if (curr == NULL) return NULL;

    // Case 1: Right subtree exists → successor = minimum of right subtree
    if (curr->right != NULL)
        return findMin(curr->right);

    // Case 2: No right subtree → go up the ancestors
    struct node* successor = NULL;
    struct node* ancestor = root;

    while (ancestor != curr) {
        if (curr->data < ancestor->data) {
            successor = ancestor;
            ancestor = ancestor->left;
        } else {
            ancestor = ancestor->right;
        }
    }
    return successor;
}


struct node* inorderPredecessor(struct node* root, int key) {
    struct node* curr = searchNonRecursive(root, key);
    if (curr == NULL) return NULL;

    // Case 1: Left subtree exists → predecessor = maximum of left subtree
    if (curr->left != NULL)
        return findMax(curr->left);

    // Case 2: No left subtree → search ancestors
    struct node* predecessor = NULL;
    struct node* ancestor = root;

    while (ancestor != curr) {
        if (curr->data > ancestor->data) {
            predecessor = ancestor;
            ancestor = ancestor->right;
        } else {
            ancestor = ancestor->left;
        }
    }
    return predecessor;
}


void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct node* root = NULL;

    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++)
        root = insert(root, arr[i]);

    printf("Inorder traversal: ");
    inorder(root);

  
    int key = 40;
    printf("\n\nSearching %d (recursive): ", key);
    struct node* s1 = searchRecursive(root, key);
    printf(s1 ? "Found" : "Not Found");

    printf("\nSearching %d (non-recursive): ", key);
    struct node* s2 = searchNonRecursive(root, key);
    printf(s2 ? "Found" : "Not Found");

    printf("\n\nMinimum in BST = %d", findMin(root)->data);
    printf("\nMaximum in BST = %d", findMax(root)->data);

    // Successor & Predecessor
    struct node* suc = inorderSuccessor(root, 50);
    struct node* pre = inorderPredecessor(root, 50);

    printf("\n\nInorder Successor of 50 = %d", suc ? suc->data : -1);
    printf("\nInorder Predecessor of 50 = %d\n", pre ? pre->data : -1);

    return 0;
}

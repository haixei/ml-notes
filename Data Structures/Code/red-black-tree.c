#include <stdio.h>

// Create the colors
#define Red 0
#define Black 1

// Basic node structure
struct Node{
    int data;
    int color;
    struct Node *left, *right, *parent;
};

// Rotate to the left
void rotateLeft(struct Node **root, struct Node *x){
    // Make the y's left child x's right child and update the pointer
    struct Node *y = x->right;
    x->right = y->left;

    if (x->right != NULL)
        x->right->parent = x;

    // Update the parent of y to be the parent of x, if x doesn't have a parent
    // make y a root of the tree
    y->parent = x->parent;
    if (x->parent == NULL)
        (*root) = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else x->parent->right = y;

    // Make x as left child of y and update the y's pointer
    y->left = x;
    x->parent = y;
}

// Rotate to the right
// Operations are basically the same but go in a different way, see the
// explanation document for visualisation
void rotateRight(struct Node **root, struct Node *y){
    struct Node *x = y->left;
    y->left = x->right;

    if (x->right != NULL)
        x->right->parent = y;

    x->parent = y->parent;
    if (x->parent == NULL)
        (*root) = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else y->parent->right = x;

    // Make x as left child of y and update the y's pointer
    x->right = y;
    y->parent = x;
}

int main(){
    struct Node *root = NULL;
    // Test the code
    return 0;
}

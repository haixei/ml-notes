#include <stdio.h>
#include <stdlib.h>

// Our basic Node structure
struct Node {
    int data;
    struct Node* next;
};

// Go trough all elements in the linked list and print their data
void printAllData(struct Node* n)
{
    while (n != NULL) {
        printf(" %d ", n->data);
        n = n->next;
    }
}

// Create new head node, time complexity O(1), we're only changing the head reference to our new node
// and pointing it to the previous head node
void appendNewHead(struct Node** head_ref, int data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data  = data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}

// Create a new node in-between already existing ones, to do that we only need to change the pointer of the
// previous node to link to our new node, and make our new node point to the next one in line
void insertBetween(struct Node* prev_node, int data)
{
    if (prev_node == NULL)
    {
        printf("The previous node cannot be NULL");
        return;
    }

    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data  = data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Insert a new node at the end of the list
void append(struct Node** head_ref, int data){
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node *last = *head_ref;

    new_node->data  = data;
    new_node->next = NULL;

    // Create the first node if a list is empty
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    // Loop till there is no next pointer
    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    return;
}

int main() {
    // Start with an empty list
    struct Node* head = NULL;

    // Test the functions
    append(&head, 6);
    appendNewHead(&head, 7);
    appendNewHead(&head, 1);
    append(&head, 4);
    insertBetween(head->next, 24);

    printf("\n Created list: ");
    printAllData(head);
    return 0;
}

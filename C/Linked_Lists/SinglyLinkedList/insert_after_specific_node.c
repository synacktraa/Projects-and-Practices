#include<stdio.h>
#include<stdlib.h>

struct Node { // structure definition

    int val; // Data of integer type;
    struct Node* next; // Pointer to the next node;
} ;

typedef struct Node Node; // typedefing struct Node to Node


// Function to display Linked list
void display(Node* root) { 

    Node* current = root; // current is set to node
    printf("[ ");
    while(current != NULL){ // loop until current is not NULL

        // if it's NULL, it means the end of the list
        printf("%d ", current->val); // prints current val member
        current  = current->next; // shift current to next node
    }
    printf("]\n");
}


// Function to insert from end in a Linked list
void append(Node** root, int vl) {

    // allocated memory for new node
    Node* new_node = (Node*)malloc(sizeof(Node));
    if(new_node == NULL) //checks for NULL value, if yes then program exits
        exit(1);

    // as we are inserting from end, we set new node's pointer
    // to NULL, to signify the end of the list
    new_node->next = NULL;
    new_node->val = vl; // setting new node val member to vl

    if(*root == NULL){ 
        /*
            if list has no value, it is set to new_node
        */
        *root = new_node;
        return;
    }

    Node* current = *root;
    //while current next member is not NULL
    while(current->next != NULL)
        //current node is shifted to next one
        current = current->next;
    
    // setting current next member to new node
    current->next = new_node;
}

/*
    Function to insert after specific Node
*/
void insert_after(Node* node, int vl) {
    
    /* This function will be useful while inserting
       in a sorted linked list
    */
    
    // Allocating space for new node
    Node* new_node = (Node*)malloc(sizeof(Node));
    if(new_node == NULL)
        exit(1);

    // setting new node val to vl
    new_node->val = vl;
    // Point the new node's pointer to node's pointer
    new_node->next = node->next;
    // Point the node's pointer to new node
    node->next = new_node;
    
}

int main(void) {

    Node* root = NULL;
    append(&root, 18); // insert 18 at the end;
    append(&root, 90); // insert 90 at the end;
    append(&root, 21); // insert 21 at the end;
    insert_after(root->next, 54); // inserting after root next member  

    display(root); // print the linked list
    //result: [ 18 90 54 21 ]
    return 0;
}
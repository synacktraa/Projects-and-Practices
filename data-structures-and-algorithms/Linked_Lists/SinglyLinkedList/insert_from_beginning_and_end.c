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

/* 
    Function to insert at the end in a Linked list
*/
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
    //while current's pointer is not NULL
    while(current->next != NULL)
        //current node is shifted to next pointer
        current = current->next;
    
    // setting current's pointer to new node
    current->next = new_node;
}

/* 
    Function to insert from beginning in a Linked list
*/
void beginsert(Node** root, int vl) {

    // allocating space for new node
    Node* new_node = (Node*)malloc(sizeof(Node));
    // if new node is NULL, program exits
    if(new_node == NULL)
        exit(1);

    // new node val member is set to vl
    new_node->val = vl;
    /* Point the new node's pointer to the root node we want to insert into,
       now new node stores the linked list we want after inserting
       new value in the beginning, we just to update our root node to new_node
    */
    new_node->next = *root;
    // Updating the root to the new node 
    *root = new_node;
}

int main(void) {

    Node* root = NULL;
    beginsert(&root, 78); // insert 78 at the beginning;
    append(&root, 19); // insert 19 at the end;
    append(&root, 6); // insert 6 at the end;
    beginsert(&root, 8); // insert 8 at the beginning;

    /*
        don't ever forget to free allocated memory BAKA ^_^ ,
        will be adding deallocation function in a separate file. 
    */
    
    display(root); // print the linked list

    //result: [ 8 78 19 6 ]
    return 0;
}
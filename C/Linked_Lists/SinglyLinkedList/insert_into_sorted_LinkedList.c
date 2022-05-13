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

// Function to insert from beginning in a Linked list
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

//Function to insert after specific Node
void insert_after(Node* node, int vl) {
    
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

/*
    Function to insert into a sorted Linked list
*/
void sorted_insert(Node** root, int vl) {

    // if list is empty or the value to insert is
    // less than list's first value
    if((*root == NULL) || vl <= ((*root)->val)){
        // insert vl at the beginning of the list
        beginsert(root, vl); 
        return;
    }

    Node* current = *root;
    Node* aux;

    // while current val membert is less than vl and current pointer is not NULL
    while(current->val < vl && current->next != NULL) {

        // aux node is set to current node
        aux = current;
        // shift current to next pointer
        current = current->next;
    }

    // if current val member is less than or equal vl
    // which means it's the end of the list
    if(current->val <= vl)
        // append vl
        append(root, vl);
    else
        // else insert vl after aux
        insert_after(aux, vl);

}

int main(void) {

    Node* root = NULL;
    append(&root, 10); // insert 18 at the end;
    append(&root, 21); // insert 21 at the end;
    append(&root, 43); // insert 90 at the end;
    sorted_insert(&root, 32); // insert 32 in a sorted linked list

    display(root); // print the linked list
    //result: [ 10 21 32 43 ]
    return 0;
}
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
        //current node is shifted to next pointer
        current = current->next;
    
    // setting current next member to new node
    current->next = new_node;
}

void dalloc(Node** root) {

    Node* current = *root;
    // loops until the end of the list
    while(current != NULL) {

        // auxiliary node stores the current node
        Node* auxiliary = current;
        // shift and increment the current pointer
        current = current->next;
        // free the auxiliary node
        free(auxiliary);
    }
    // set root node to NULL
    *root = NULL;
}

int main(void) {

    Node* root = NULL;
    append(&root, 18); // insert 18 at the end;
    append(&root, 10); // insert 10 at the end;
    append(&root, 90); // insert 90 at the end;
    append(&root, 74); // insert 74 at the end;

    display(root); // print the linked list
    dalloc(&root); // deallocates the allocated memory for linked list
    //result: [ 18 10 90 74 ]
    return 0;
}
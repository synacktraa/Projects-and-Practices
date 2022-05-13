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

/*
    Function to remove a node with a specified value
*/
void _remove(Node** root, int vl) {

    // if list is empty, there's no need to remove anything
    if(*root == NULL)
        return;
    
    Node* aux;
    // if list's first value is equal to given value (vl)
    if((*root)->val == vl) {
        // aux stores the first node
        aux = *root;
        // root is incremented
        (*root) = (*root)->next;  
        // then free the aux node
        free(aux);
        return; 
    }

    aux = *root;
    Node* current;
    // while current val member is not equal given value
    // and not the end of the list
    while(aux->val != vl && aux->next != NULL){
        // aux stores the aux node
        current = aux;
        // aux is incremented
        aux = aux->next;
    }

    // if aux's pointer is NULL,
    // then given value is not present in list
    if(aux->next == NULL)
        return;

    // current's pointer stores the aux's pointer
    current->next = aux->next;
    // free aux node
    free(aux);
}

int main(void) {

    Node* root = NULL;
    append(&root, 18); // insert 18 at the end;
    append(&root, 10); // insert 10 at the end;
    append(&root, 90); // insert 90 at the end;
    append(&root, 74); // insert 74 at the end;

    _remove(&root, 10);
    display(root); // print the linked list
    //result: [ 18 90 74 ]
    return 0;
}

#include<stdio.h>

#define DEPTH 50
#define EMPTY -1

int top = EMPTY;
int stack[DEPTH];


// Function to push element at the top of the stack
void push(int val) {

    if(top >= DEPTH-1){ 
        printf("Stack Overflow");
        return;
    }
    stack[++top] = val;
}

// Function to pop the element at the top of the stack
void pop() {

    if(top == EMPTY){
        printf("Stack Underflow\n");
        return;
    }
    printf("%d\n", stack[top--]);
}

// Function to print the element at the top of the stack
void peek() {
    if(top == EMPTY) {
        printf("Nothing to peek!\n");
        return;
    }
   printf("%d\n", stack[top]);
}

// Function to print the stack
void display() {
    if(top == EMPTY) {
        printf("Nothing to display!\n");
        return;
    }

   printf("[ ");
    for(int idx=top; idx >= 0; --idx)
       printf("%d ", stack[idx]);
   printf("]\n");
}

int main(void) {

    push(90);
    push(80);
    push(78);
    push(43);
    display();
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    display();
    
    /* STDOUT
        [ 43 78 80 90 ]
        43
        78
        80
        90
        Stack Underflow
        Stack Underflow
        Nothing to display!
    */
    
    return 0;
}
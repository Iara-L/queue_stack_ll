#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 101
int stack[MAX_SIZE];
int top = -1;

void pop(){
    if(top == -1){
        perror("Stack is empty\n");
        return;
    }
    for(int i = 0; i < top; i++){
        stack[i] = stack[i + 1];
    }
    top--;
}

void push(int data){
    if(top == MAX_SIZE - 1){
        perror("Stack overflow\n");
        return;
    }
    stack[++top] = data;
}

void print_top(){
    printf("%d\n", top);
}

void print(){
    for (int i = 0; i <= top; i++){
        printf("%d\t", stack[i]);
    }
    printf("\n");
}

int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);

    print();
    print_top();

    pop();
    pop();
    
    print();
    print_top();

    return 0;
}
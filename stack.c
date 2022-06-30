#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

void push_end(Node* first, int d);
void delete_end(Node* first);

void print_stack(Node* first);

int main(){
    int N, d;
    scanf("%d", &N);

    Node* first = malloc(sizeof(Node));
    scanf("%d", &(first->data));
    
    for (int i = 1; i < N; i++){
        scanf("%d", &d);
        push_end(first, d);
    }
    
    print_stack(first);
    delete_end(first);
    print_stack(first);


    return 0;
}

void push_end(Node* first, int d){
    Node* current = first;

    while (current->next){
        current = current->next;
    }
    Node* new_node = malloc(sizeof(Node));
    current->next = new_node;
    new_node->data = d;
}

void delete_end(Node* first){
    Node* current = first;
    Node* prev = current;

    while (current->next){
        prev = current;
        current = current->next;
    }
    free(current);
    prev->next = NULL;
}

void print_stack(Node* first){
    Node* current = first;

    while(current){
        printf("%d\t", current->data);
        current = current->next;
    }
    printf("\n");
}
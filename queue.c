#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

void delete_first(Node** first);
//void add_first(Node** first, int data);
void push(Node* first, int d);
void print_queue(Node* first);

int main(){
    int N, d;
    scanf("%d", &N);

    Node* first = malloc(sizeof(Node));
    scanf("%d", &(first->data));

    for (int i = 1; i < N; i++){
        scanf("%d", &d);
        push(first, d);
    }
    
    print_queue(first);
    delete_first(&first);
    print_queue(first);

    return 0;
}

void delete_first(Node** first){
    Node* current = *first;
    *first = current->next;
    free(current);
}

// void add_first(Node** first, int d){
//     Node* new_node = malloc(sizeof(Node));
//     new_node->next = *first;
//     new_node->data = d;

//     *first = new_node;
// }

void push(Node* first, int d){
    Node* current = first;

    while(current->next){
        current = current->next;
    }
    Node* new_node = malloc(sizeof(Node));
    current->next = new_node;
    new_node->data = d;
    new_node->next = NULL;
}

void print_queue(Node* first){
    Node* current = first;

    while (current){
        printf("%d\t", current->data);
        current = current->next;
    }
    printf("\n");
}
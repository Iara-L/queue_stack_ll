#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

Node* create_node(int d);
void push_begin(Node** first, Node* to_add);
void push_end(Node* first, Node* to_add);

void print_list(Node* first);

void delete_node(Node** first, int index);
void delete_list(Node* first);

int main(int argc, char **argv){
    Node* first = create_node(atoi(argv[2]));

    for (int i = 1; i < atoi(argv[1]); i++) {
        Node* node = create_node(atoi(argv[2 + i]));
        push_end(first, node);
    }
    
    print_list(first);
    printf("\n");

    delete_node(&first, 2);

    print_list(first);
    printf("\n");
    
    delete_list(first);

    return 0;
}

Node* create_node(int d){
    Node* new_node = malloc(sizeof(Node));
    new_node->data = d;

    return new_node;
}

void push_begin(Node** first, Node* to_add){
    to_add->next = *first;
    *first = to_add;
}

void push_end(Node* first, Node* to_add){
    Node* current = first;

    while (current->next){
        current = current->next;
    }
    current->next = to_add;
}

void print_list(Node* first){
    Node* current = first;

    while(current){
        printf("%d\t", current->data);
        current = current->next;
    }
}

void delete_node(Node** first, int index){
    Node* current = *first;
    Node* prev = current;
    int counter = 0;

    if(index == 0){
        *first = current->next;
        free(current);
        return;
    }

    while (current){
        if(counter == index){
            prev->next = current->next;
            free(current);
            return;
        }
        counter++;
        prev = current;
        current = current->next;
    }
}

void delete_list(Node* first){
    Node* current = first;

    while (current){
        Node* prev = current;
        current = current->next;
        free(prev);
    }
}
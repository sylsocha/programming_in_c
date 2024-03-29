#include <stdio.h>
#include <malloc.h>

typedef struct node {
    int val;
    struct node * next;
} node_t;

void base_nodes(node_t * head){
    node_t * current = head->next;
    current->val = 2;
    current->next = (node_t *) malloc(sizeof(node_t));

    for(int i = 3; i<=5; i++){
        current = current->next;
        current->val = i;
        current->next = (node_t *) malloc(sizeof(node_t));
    }
    current->next = NULL;
}

void print_list(node_t * head, int nr_zad){

    node_t * current = head;
    printf("Zadanie %d\n", nr_zad);

    while(current !=NULL){
        printf("%d\n", current->val);
        current = current->next;
    }
}

void remove_last(node_t * head){

    node_t * last = head->next;
    node_t * previous = head;

    while(last->next != NULL){  //znalezienie przedostatniego elementu listy
        last = last->next;
        previous = previous->next;
    }
    previous->next = NULL;
}

void remove_at_index(node_t * head, int index){
    node_t * remove = head;

    for(int i = 0; i < index; i++){
        remove = remove->next;
    }

    if(remove->next != NULL){
        remove->val = remove->next->val;
        remove->next = remove->next->next;
    }
    else{
        remove_last(head);
    }
}

void remove_value(node_t * head, int value){
    node_t * remove = head;

    while(remove->val != value){
        remove = remove->next;
    }

    if(remove->next != NULL){
        remove->val = remove->next->val;
        remove->next = remove->next->next;
    }
    else{
        remove_last(head);
    }
}

void add_at_index(node_t * head, int index){
    
}

int main(){

    int nr_zad;
    //utworzenie listy
    node_t * head = (node_t *) malloc(sizeof(node_t));
    head->val = 1;
    head->next = (node_t *) malloc(sizeof(node_t));
    base_nodes(head);

    // zadanie 1
    nr_zad = 1;

    node_t * push = (node_t *) malloc(sizeof(node_t ));
    if(push != NULL){
        push->val = 0;
        push->next = head;
        head = push;
    }

    print_list(head, nr_zad);

    //zadanie 2
    nr_zad++;

    head->val = head->next->val;
    head->next = head->next->next;

    print_list(head, nr_zad);

    //zadanie 3
    nr_zad++;

    remove_last(head);
    print_list(head, nr_zad);

    // zadanie 4
    nr_zad++;

    int index = 2;

    remove_at_index(head, index);
    print_list(head, nr_zad);

    // zadanie 5
    nr_zad++;

    int value = 2;

    remove_value(head, value);
    print_list(head, nr_zad);

    //zadanie 6
    nr_zad++;

    index = 1;
    add_at_index(head, index);
    print_list(head, nr_zad);

    return 0;
}

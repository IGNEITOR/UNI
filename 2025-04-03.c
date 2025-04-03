#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;


node_t *new_node(int val){
    node_t *node = (node_t*) malloc(sizeof(node_t));
    node->data = val;
    node->next = NULL;
return node;
}

void add_node(node_t *head, int val){
    if(head==NULL){
        printf("Error: Leere Liste");
        exit(-1);
    }
    node_t *curr = head;
    while(curr->next!=NULL){
    curr = curr->next;
    }
    node_t *e = new_node(val);
    curr->next = e;
}

void print_list(node_t *head){
    node_t *curr = head;
    while(curr!=NULL){
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

void main(){
    node_t *head = new_node(1);
    add_node(head,2);
    add_node(head,3);
    add_node(head,4);
    add_node(head,5);
    while(head != NULL){
        printf("%d ->",head->data);
        head = head->next;
    }
    //printf("NULL\n");
    print_list(head);
}
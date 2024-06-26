// Name:  Yinxia Shi
// Email: shi.yinx@northeastern.edu

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node_t;

typedef struct list{
    struct node* head;
} List;

/*-----creating the nodes----------*/
node_t* newNode(int num) {
    node_t* temp = malloc(sizeof(node_t));
    if (temp == NULL) {
        printf("Failed to create new Node\n");
        exit(1);
    }
    temp->data = num;
    temp->next = NULL;
    return temp;
}

/*---creating linked list----*/
List* init_LL() {
    List* temp = malloc(sizeof(List));
    if (temp == NULL) {
        printf("Failed to create a new List\n");
        exit(1);
    }
    temp->head = NULL;
    return temp;
}

/*---Insert the nodes at the begining of the list---*/
void insertFirst(List* l, int data) {
    node_t* preHead = l->head;
    l->head = newNode(data);
    l->head->next = preHead; 
}

/*----display the output--------*/
void display(List* l) {
    node_t* temp;
    temp = l->head;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/*-------reversing the linked list using recursion------*/
void reverse(List* l, node_t* ptr) {
    //insert your code here
    if (ptr == NULL) {
        return;
    }
    if (ptr->next == NULL) {
        l->head = ptr;
        return;
    }
    reverse(l, ptr->next);
    ptr->next->next = ptr;
    ptr->next = NULL;
}

/*----Free the nodes-----*/
void freenode(List* l) {
    node_t* temp;
    while (l->head) {
        temp = l->head->next;
        free(l->head);
        l->head = temp;
    }
}

/*-----Main program--------------*/
int main() {
    List* list = init_LL();

    insertFirst(list, 44);
    insertFirst(list, 33);
    insertFirst(list, 22);
    insertFirst(list, 11);
    display(list);
    reverse(list, list->head);
    display(list);
    
    freenode(list);
    free(list);
    return 0;
}

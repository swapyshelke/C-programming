#include<stdio.h>
#include<stdlib.h>

void beg_insert(int);
void last_insert(int);

struct node {
    int data;
    struct node *next;
}*head = 0;

void main(){
    int choice, item;

    do{
        printf("Enter the item which you want to insert \n");
        scanf("%d", &item);

        // beg_insert(item);
        last_insert(item);

        printf("\n Press 0 to insert more \n");
        scanf("%d", &choice);
    } while(choice == 0);
}

void beg_insert(int item) {
    struct node *ptr;

    ptr = (struct node *)malloc(sizeof(struct node *));

    if(ptr == NULL) {
        printf("\n overflow \n");
    } else {
        ptr->data = item;
        ptr->next = NULL;
        head = ptr;
        printf("\n node inserted \n");
    }
}

void last_insert(int item) {
    struct node* ptr;

    ptr = (struct node *)malloc(sizeof(struct node ));

    struct node *temp;

    if(ptr == NULL){
        printf("\n overflow \n");
    } else {
        ptr->data = item;

        if(head == NULL) {
            
        }
    }
}
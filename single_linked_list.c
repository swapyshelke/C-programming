#include <stdlib.h>
#include <stdio.h>

struct node
{
    int data;
    struct node *next;
} *list, *p, *q;

int no=1, i = 1;


void create(){
    for(i=1; i<=no; i++){
        p = (struct  node *) malloc(sizeof(struct node));
        p->next = 0;
        printf("Enter data for node %d", i);
        scanf("%d", &p->data);

        // list = p;

        if(list == NULL){
            list = q = p;
        } else {
            q->next = p;
            q=p;
        }
    }
}

void display(){
    struct node *t = list;
    // t=t->next;
    
    while(t){
        printf("\t %d", t->data);
        t=t->next;
    }
}

void insert(int pos){
      p = (struct node *)malloc(sizeof(struct node));
    printf("Enter data for the new node: ");
    scanf("%d", &p->data);
    p->next = NULL;

    if (pos == 1) {
        p->next = list;
        list = p;
    } else {
        q = list;
        for (int i = 1; i < pos - 1; i++) {
            q = q->next;
        }
        p->next = q->next;
        q->next = p;
    }
    no++;
    printf("Node inserted\n");
}

void delete(int pos){
    if(pos == 1){
        p=list;
        if(list->next == list){
            list = NULL;
        } else {
            list = list->next;
        }
    }else {
        q=list;
        
        for(int i=1; i<pos - 1; i++) {
            q=q->next;
        } 
        p=q->next;
        q->next = p->next;
    }
    p->next = 0;
    printf("%d", p->data);
    free(p);
    p=0;
    // struct node *nextnode;
    // // int pos, i=1;
    // p =list;
    
    // while(i<pos - 1) {
    //     q = q->next;
    //     i++;
    // }
    
    // nextnode = q->next;
    // q->next = nextnode->next;
    // free(nextnode);
}


int main()
{

    int ch, pos;

    do
    {
        printf("Enter number of nodes you want : \n");
        scanf("%d", &no);
    } while (no < 1);

    create();

    do
    {
        printf("\n1. Display linked list");
        printf("\n2. Insert node");
        printf("\n3. Delete node");
        printf("\n4. Stop code");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            if (list == 0)
                printf("SLL is empty");
            else
                display();
            break;
        case 2:
            printf("Enter position \n");
            scanf("%d", &pos);

            if (pos >= 1 && pos <= no + 1)
                insert(pos);
            else
                printf("Position is invalid \n");
            break;
        case 3:
            printf("Enter position to delete node:  ");
            scanf("%d", &pos);

            if (pos >= 1 && pos <= no)
                delete (pos);
            else
                printf("Position is invalid \n");
            break;
        case 4:
            exit(0);
        }

    } while (ch > 0 && ch < 5);

    return 0;
}



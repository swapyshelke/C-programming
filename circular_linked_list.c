#include <stdlib.h>
#include <stdio.h>

struct node
{
    int data;
    struct node *next;
} *list = NULL, *p, *q;

int no = 0;

void create() {
    for (int i = 1; i <= no; i++) {
        p = (struct node *)malloc(sizeof(struct node));
        printf("Enter data for node %d: ", i);
        scanf("%d", &p->data);

        if (list == NULL) {
            list = p;
            p->next = list; // Point to itself to create circularity
            q = p;
        } else {
            q->next = p;
            p->next = list; // Complete the circle
            q = p;
        }
    }
}

void display() {
    if (list == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *t = list;
    do {
        printf("\t %d", t->data);
        t = t->next;
    } while (t != list);
    printf("\n");
}

void insert(int pos) {
    struct node *p = (struct node *)malloc(sizeof(struct node));
    printf("Enter data for the new node: ");
    scanf("%d", &p->data);

    if (pos == 1) {
        if (list == NULL) {
            list = p;
            p->next = list; // Point to itself to create circularity
        } else {
            p->next = list;

            q = list;
            while (q->next != list) {
                q = q->next;
            }
            q->next = p; // Update the last node's next pointer
            list = p;    // Update the head pointer
        }
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

void delete(int pos) {
    if (list == NULL) {
        printf("List is empty\n");
        return;
    }

    if (pos == 1) {
        if (list->next == list) {
            printf("Deleted node data: %d\n", list->data);
            free(list);
            list = NULL;
        } else {
            q = list;
            while (q->next != list) {
                q = q->next;
            }
            p = list;
            q->next = list->next;
            list = list->next;
            printf("Deleted node data: %d\n", p->data);
            free(p);
        }
    } else {
        q = list;
        for (int i = 1; i < pos - 1; i++) {
            q = q->next;
        }
        p = q->next;
        q->next = p->next;
        printf("Deleted node data: %d\n", p->data);
        free(p);
    }
    no--;
}

int main() {
    int ch, pos;

    do {
        printf("Enter number of nodes you want: ");
        scanf("%d", &no);
    } while (no < 1);

    create();

    do {
        printf("\n1. Display linked list");
        printf("\n2. Insert node");
        printf("\n3. Delete node");
        printf("\n4. Stop code\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                if (list == NULL)
                    printf("Circular linked list is empty\n");
                else
                    display();
                break;
            case 2:
                printf("Enter position to insert node: ");
                scanf("%d", &pos);

                if (pos >= 1 && pos <= no + 1)
                    insert(pos);
                else
                    printf("Position is invalid\n");
                break;
            case 3:
                printf("Enter position to delete node: ");
                scanf("%d", &pos);

                if (pos >= 1 && pos <= no)
                    delete(pos);
                else
                    printf("Position is invalid\n");
                break;
            case 4:
                exit(0);
        }

    } while (ch > 0 && ch < 5);

    return 0;
}

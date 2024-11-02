// Queue implementation using Array
// operations - enqueue, dequeue, display 


#include <stdio.h>
#include <stdlib.h>
#define MAX 10

// function declarations
void insert();
void delete();
void display();

// array initialization
int que_arr[MAX];

int rear = -1;
int front = -1;


void insert(){
    
    int add_item;
    
    if(rear == MAX -1){
        printf("Queue is fulled. Overflow\n");
    }
    
    if(front == -1) 
        front = 0;
        
        printf("Enter elelemtn to insert \n");
        scanf("%d", &add_item);
        rear = rear + 1;
        que_arr[rear] = add_item;
        printf("Element inserted is -> %d \n", add_item);
    
}

void delete(){
    // check queue is empty or not
    if (front == -1 || front > rear){
        printf("Queue is empty\n");
        return;
    } else {
        printf("Element deleted from queue is %d\n", que_arr[front]);
        front = front +  1;
    }
}

void display(){
    if(rear == -1){
        printf("Queue is empty \n");
    } else {
        int i;
        for(i = front; i <= rear; i++){
            printf("%d\n", que_arr[i]);
        }
        printf("\n");
    }
}



int main()
{
    
    int choice; 
    
    while(1){
        printf("Enter choice \n");
    scanf("%d", &choice);
    
    switch(choice){
        case 1:
        printf("1. Insert Element\n");
        insert();
        break;
        case 2:
        printf("2. Delete Element\n");
        delete();
        break;
        case 3:
        printf("3. Display Elements\n");
        display();
        break;
        case 4:
        printf("Exit \n");
        exit(1);
        break;
        default:
        printf("Enter right choice \n");
    }
}

    return 0;
}

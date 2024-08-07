// implement stack using linked list 

#include<stdio.h>
#include<stdlib.h>

struct stack {
    int d;
    struct stack *next;
};

struct stack* push(struct stack *t, int x);
struct stack* pop(struct stack *t);
void display(struct stack *t);
int peek(struct stack *t);

int main(){
    
    int choice, x;
    
    struct stack *top = NULL; 
        // denote that stack is empty
        
        do{
            printf("1. Push \n 2. Pop \n 3. Display \n 4. Peek \n 5. End Execution");
            scanf("%d", &choice);
            
            switch(choice) {
                case 1: 
                        printf("enter data");
                        scanf("%d", &x);
                        top = push(top, x);
                    break;
                case 2: 
                    top = pop(top);
                    break;
                case 3:
                        display(top);
                    break;
                case 4: 
                       printf("Top element is: %d\n", peek(top));
                    break;
                case 5: 
                        exit(0);
                
            }
        } while(choice >= 1 && choice < 6);
        
        
        
    return 0;
}


struct stack* push(struct stack *t, int x){
    struct stack *p;
    
    p = (struct stack *) malloc(sizeof(struct stack));
    
    p->d = x;
    // p->next = NULL;
    
    if(t == 0) 
        t=p;
    // if t==0 means, if stack is empty, 
    // then assign address of p(new node) to t pointer, 
    // which rep. top pointer 
    
    else {
        p->next = t;
        t=p;
    }
    
    return t;
    
}


struct stack* pop(struct stack *t) {
    struct stack *p = t;
    
    // int ans;
    printf("%d", p->d);
    
    // ans = p->data;
    
    t=t->next;
    free(p);
    p=0;
    
    return t;
}

void display(struct stack *t){
    if(t == NULL) {
        printf("stack is empty. \n");
        return;
    }
    
    
    printf("stack elementss: \n");
    
    struct stack *p = t;
    
    while(p != 0){
        printf("%d \n", p->d);
        p = p->next;
    }
}



int peek(struct stack *t) {
    if(t == NULL) {
        printf("Stack is empty.\n");
        return -1;
    }
    return t->d;
}


// complete code of Stack Implementation using Linked List

// implement stack using linked list 

#include<stdio.h>
#include<stdlib.h>

struct stack {
    int d;
    struct stack *next;
};

int main(){
    
    int choice, x;
    
    struct stack *top = NULL; 
        // denote that stack is empty
        
        do{
            printf("1. Push \n 2. Pop \n 3. Display \n 4. Peek \n 5. End Execution");
            scanf("%d", &choice);
            
            scitch(choice) {
                case 1: printf("enter data");
                        scanf("%d", &x);
                        top = push(&top, x);
                    break;
                case 2: top = pop();
                    break;
                case 3:
                        display();
                    break;
                case 4: 
                        peek();
                    break;
                case 5: 
                        exit(0);
                
            }
        } while(choice >= 1 && ch < 6);
        
        
        
    return 0;
}


struct stack push(struct stack *t, int x){
    struct stack *p;
    
    p = (struct stack *) malloc(sizeof(struct stak));
    
    p->d = x;
    p->next = NULL;
    
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


int pop(struct stack *t) {
    struct stack *p = t;
    
    // int ans;
    printf("%d", p->d);
    
    // ans = p->data;
    
    t=t->next;
    free(p);
    p=0;
    
    return t;
}

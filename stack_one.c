// Implementing Stach using C programming
// Using Array's

#include <stdio.h>

#define MAX 3

struct stack {
    int data[MAX];
    int top;
};

// functoin prototype

void push(struct stack *p, int x);
int pop(struct stack *p);
void display(struct stack *p);
int peek(struct stack *p);

int main() {
  struct stack S1;
  
  int ch, x;
  
  S1.top = -1;
  
  do{
  printf("Enter your choices : \n");
  printf("1. PUSH \n 2. POP \n 3. Display \n 4. Peek \n 5. Stop Execution");
  scanf("%d", &ch);
 
  
  switch(ch){
      case 1: if(S1.top == -1)
                printf("Stack is empty");
            else{
                // take data from user 
                printf("enter data for element :\n");
                scanf("%d", &x);
                push(&S1, x);
            } 
            
            break;
        case 2: if(S1.top == -1)
                    printf("Stack is empty");
                else
                    printf("%d", pop(&S1));
                break;
        case 3: if(S1.top == -1)
                    printf("stack is empty");
                else
                   display(&S1);
                break;
        case 4:  if(S1.top == -1)
                    printf("stack is empty");
                else 
                   printf("Top element is %d",  peek(&S1));
        case 5:
                printf("Stopping execution\n");
                break;
          default:
                printf("Invalid choice, please enter a valid choice\n");
                break;
}  } while(ch >= 1 && ch < 5);
 
    return 0;
}

// void push(struct satck *p, int x);
void push(struct stack *p,int x){
    // 1. increment top
    // 2. insert element
    p->top++;
    p->data[p->top] = x;
}

int pop(struct stack *p){
    return (
            p->data[p->top--]
        );
}

void display(struct stack *p){
    for(int i=p->top; i != -1; i--){
        printf("%d \n", p->data[i]);
    }
}

int peek(struct stack *p) {
    return (
        p->data[p->top]
        );
}

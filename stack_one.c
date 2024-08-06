// Implementing Stach using C programming
// Using Array's
#include <stdio.h>

#define MAX 3

struct stack {
    int data[MAX];
    int top;
};

// Function prototypes
void push(struct stack *p, int x);
int pop(struct stack *p);
void display(struct stack *p);
int peek(struct stack *p);

int main() {
    struct stack s1;
    int ch, x;

    s1.top = -1;

    do {
        printf("Enter your choice:\n");
        printf("1. PUSH\n2. POP\n3. Display\n4. Peek\n5. Stop Execution\n");
        scanf("%d", &ch);

        switch(ch) {
            case 1: 
                if(s1.top == MAX - 1) {
                    printf("Stack is full\n");
                } else {
                    printf("Enter data for element:\n");
                    scanf("%d", &x);
                    push(&s1, x);
                }
                break;
            case 2: 
                if(s1.top == -1) {
                    printf("Stack is empty\n");
                } else {
                    printf("Popped element: %d\n", pop(&s1));
                }
                break;
            case 3:
                if(s1.top == -1) {
                    printf("Stack is empty\n");
                } else {
                    display(&s1);
                }
                break;
            case 4:
                if(s1.top == -1) {
                    printf("Stack is empty\n");
                } else {
                    printf("Top element: %d\n", peek(&s1));
                }
                break;
            case 5:
                printf("Stopping execution\n");
                break;
            default:
                printf("Invalid choice, please enter a valid choice\n");
                break;
        }
    } while(ch != 5);

    return 0;
}

void push(struct stack *p, int x) {
    p->top++;
    p->data[p->top] = x;
}

int pop(struct stack *p) {
    return p->data[p->top--];
}

void display(struct stack *p) {
    for(int i = p->top; i >= 0; i--) {
        printf("%d\n", p->data[i]);
    }
}

int peek(struct stack *p) {
    return p->data[p->top];
}

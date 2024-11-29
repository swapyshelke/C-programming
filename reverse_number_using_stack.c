#include <stdio.h>
#define MAX 7
#define TRUE 1
#define FALSE 0

struct Stack {
    int top;
    int array[MAX];
} st;

void initialize() {
    st.top = -1;
}

int isFull() {
    return st.top >= MAX - 1 ? TRUE : FALSE;
}

int isEmpty() {
    return st.top == -1 ? TRUE : FALSE;
}

void push(int x) {
    if (isFull())
        printf("Stack is Full...\n");
    else {
        st.top++;
        st.array[st.top] = x;
    }
}

int pop() {
    if (isEmpty()) {
        printf("Stack is Empty...\n");
        return -1; // Return an invalid value to indicate error
    } else {
        int temp = st.array[st.top];
        st.top--;
        return temp;
    }
}

void printStack() {
    if (!isEmpty()) {
        int temp = pop();
        printStack();
        printf(" %d ", temp);
        push(temp);
    }
}

void insertAtBottom(int y) {
    if (isEmpty()) {
        push(y);
    } else {
        int top = pop();
        insertAtBottom(y);
        push(top);
    }
}

void reverse() {
    if (!isEmpty()) {
        int top = pop();
        reverse();
        insertAtBottom(top);
    }
}

int getSize() {
    return st.top + 1;
}

int main() {
    initialize();
    push(0);
    push(9);
    push(4);
    push(6);
    push(7);
    printf("Given Input Stack\n");
    printStack();
    printf("\n");

    reverse();

    printf("Reversed Given Input Stack\n");
    printStack();
    printf("\n");

    return 0;
}

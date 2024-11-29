#include <stdio.h>
#include <string.h>
#define MAX 100

// Define the stack structure
struct Stack {
    int top;
    char array[MAX];
} st;

// Function to initialize the stack
void initialize() {
    st.top = -1;
}

// Check if the stack is full
int isFull() {
    return st.top >= MAX - 1;
}

// Check if the stack is empty
int isEmpty() {
    return st.top == -1;
}

// Push a character onto the stack
void push(char ch) {
    if (isFull())
        printf("Stack is Full...\n");
    else {
        st.top++;
        st.array[st.top] = ch;
    }
}

// Pop a character from the stack
char pop() {
    if (isEmpty()) {
        printf("Stack is Empty...\n");
        return '\0'; // Return null character for empty stack
    } else {
        char temp = st.array[st.top];
        st.top--;
        return temp;
    }
}

// Function to reverse a string using a stack
void reverseString(char str[]) {
    int n = strlen(str);

    // Push all characters of the string onto the stack
    for (int i = 0; i < n; i++) {
        push(str[i]);
    }

    // Pop characters from the stack and place them back into the string
    for (int i = 0; i < n; i++) {
        str[i] = pop();
    }
}

int main() {
    char str[MAX];

    // Input string
    printf("Enter a string: ");
    fgets(str, MAX, stdin);

    // Remove the newline character if present
    str[strcspn(str, "\n")] = '\0';

    printf("Original String: %s\n", str);

    // Reverse the string
    initialize();
    reverseString(str);

    printf("Reversed String: %s\n", str);

    return 0;
}

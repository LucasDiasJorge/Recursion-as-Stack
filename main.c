#include <stdio.h>
#include <stdlib.h>

// Define the stack structure
typedef struct {
    int *data;
    int top;
    int capacity;
} Stack;

// Function to create a stack
Stack* createStack(int capacity) {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->data = (int*)malloc(capacity * sizeof(int));
    return stack;
}

// Function to push an element onto the stack
void push(Stack *stack, int value) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->data[++stack->top] = value;
}

// Function to pop an element from the stack
int pop(Stack *stack) {
    if (stack->top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack->data[stack->top--];
}

// Function to check if the stack is empty
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Function to compute the factorial using a stack
int factorial(int n) {
    Stack *stack = createStack(100);
    int result = 1;
    
    // Push all numbers from 1 to n onto the stack
    for (int i = 1; i <= n; i++) {
        push(stack, i);
    }
    
    // Pop elements from the stack and multiply
    while (!isEmpty(stack)) {
        result *= pop(stack);
    }
    
    // Free the stack
    free(stack->data);
    free(stack);
    
    return result;
}

int main() {
    int number = 5;
    printf("Factorial of %d is %d\n", number, factorial(number));
    return 0;
}

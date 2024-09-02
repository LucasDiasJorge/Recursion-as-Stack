#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef struct {
    int n;          // Valor atual de n
    int state;      // Estado da função
    int result;     // Resultado da função
} StackFrame;

typedef struct {
    StackFrame stack[MAX_STACK_SIZE];
    int top;
} Stack;

void init_stack(Stack *s) {
    s->top = -1;
}

int is_empty(Stack *s) {
    return s->top == -1;
}

int is_full(Stack *s) {
    return s->top == MAX_STACK_SIZE - 1;
}

void push(Stack *s, StackFrame frame) {
    if (is_full(s)) {
        fprintf(stderr, "Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    s->stack[++s->top] = frame;
}

StackFrame pop(Stack *s) {
    if (is_empty(s)) {
        fprintf(stderr, "Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->stack[s->top--];
}

int fibonacci(int n) {
    Stack s;
    init_stack(&s);

    // Start with the initial frame
    StackFrame initial_frame = {n, 0, 0};
    push(&s, initial_frame);

    int result = 0;

    while (!is_empty(&s)) {
        StackFrame frame = pop(&s);

        if (frame.n == 0) {
            frame.result = 0;
        } else if (frame.n == 1) {
            frame.result = 1;
        } else {
            // Push the frame for n-1
            StackFrame frame1 = {frame.n - 1, 0, 0};
            push(&s, frame1);
            
            // Push the frame for n-2
            StackFrame frame2 = {frame.n - 2, 1, 0};
            push(&s, frame2);
            
            // Set the state to combine results later
            frame.state = 2;
            push(&s, frame);
            continue;
        }

        if (frame.state == 2) {
            // Combine the results of n-1 and n-2
            StackFrame previous_frame = pop(&s);
            previous_frame.result += frame.result;
            push(&s, previous_frame);
        } else {
            // Direct result
            result = frame.result;
        }
    }

    return result;
}

int main() {
    int n = 4;
    printf("Fibonacci(%d) = %d\n", n, fibonacci(n));
    return 0;
}

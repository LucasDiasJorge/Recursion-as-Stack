# Stack-Based Factorial Calculator

This project demonstrates a stack-based approach to calculate the factorial of a number in C. The implementation avoids recursion, instead using an iterative approach with a stack data structure to manage intermediate values.

## Overview

The project includes:
- A stack data structure implemented with an array.
- Functions to push, pop, and check if the stack is empty.
- A function to calculate the factorial of a number using the stack.
- A `main` function to test the factorial calculation.

## Features

- **Stack Structure**: A custom stack structure to store integers.
- **Stack Operations**: Includes functions to create a stack, push elements onto the stack, pop elements from the stack, and check if the stack is empty.
- **Iterative Factorial Calculation**: Uses the stack to iteratively compute the factorial of a given number.
- **Memory Management**: Properly allocates and frees memory for the stack.

## Benefits of Non-Recursive Approach

1. **Avoids Stack Overflow**: Recursion can lead to stack overflow if the recursion depth is too high. The iterative approach with a custom stack prevents this issue.
2. **Better Control**: Managing the stack explicitly provides better control over memory usage.
3. **Efficiency**: The iterative approach can be more efficient in terms of both time and space complexity for large inputs.
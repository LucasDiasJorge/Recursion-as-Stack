import java.util.Stack;

public class FactorialUsingStack {

    // Function to compute the factorial using a stack
    public static int factorial(int n) {
        Stack<Integer> stack = new Stack<>();
        int result = 1;

        // Push all numbers from 1 to n onto the stack
        for (int i = 1; i <= n; i++) {
            stack.push(i);
        }

        // Pop elements from the stack and multiply
        while (!stack.isEmpty()) {
            result *= stack.pop();
        }

        return result;
    }

    public static void main(String[] args) {
        int number = 5;
        System.out.println("Factorial of " + number + " is " + factorial(number));
    }
}

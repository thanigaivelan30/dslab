#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Stack {
    int arr[MAX];
    int top;
};

void initializeStack(struct Stack *stack) {
    stack->top = -1;
}

void push(struct Stack *stack, int element) {
    if (stack->top == (MAX - 1)) {
        printf("Error: Stack overflow. Cannot push element.\n");
        return;
    }
    stack->arr[++stack->top] = element;
    printf("Element pushed: %d\n", element);
}

int pop(struct Stack *stack) {
    if (stack->top == -1) {
        printf("Error: Stack underflow. Cannot pop element.\n");
        return -1; // Note: -1 acts as an error indicator here
    } else {
        int poppedElement = stack->arr[stack->top--];
        printf("Popped element: %d\n", poppedElement);
        return poppedElement;
    }
}

void displayStack(struct Stack *stack) {
    if (stack->top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements (top to bottom): ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

int main() {
    struct Stack stack;
    int choice, element;
    
    initializeStack(&stack);

    while (1) {
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting...\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &element);
                push(&stack, element);
                break;
            case 2:
                pop(&stack);
                break;
            case 3:
                displayStack(&stack);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }
    return 0;
}

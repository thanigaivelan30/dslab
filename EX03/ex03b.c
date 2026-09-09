#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Reduced for easy testing, change to 100 as needed

struct Queue {
    int arr[MAX];
    int front;
    int rear;
};

void initializeQueue(struct Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isFull(struct Queue *queue) {
    return (queue->front == 0 && queue->rear == MAX - 1) || (queue->rear == (queue->front - 1) % (MAX - 1));
}

int isEmpty(struct Queue *queue) {
    return queue->front == -1;
}

void enqueue(struct Queue *queue, int element) {
    if (isFull(queue)) {
        printf("Error: Queue overflow. Cannot enqueue element.\n");
        return;
    }
    
    if (queue->front == -1) { // First element insertion
        queue->front = 0;
        queue->rear = 0;
    } else if (queue->rear == MAX - 1 && queue->front != 0) {
        queue->rear = 0; // Wrap around
    } else {
        queue->rear++;
    }
    
    queue->arr[queue->rear] = element;
    printf("Element enqueued: %d\n", element);
}

int dequeue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Error: Queue underflow. Cannot dequeue element.\n");
        return -1;
    }
    
    int element = queue->arr[queue->front];
    
    if (queue->front == queue->rear) { // Queue has only one element, reset
        queue->front = -1;
        queue->rear = -1;
    } else if (queue->front == MAX - 1) {
        queue->front = 0; // Wrap around
    } else {
        queue->front++;
    }
    
    return element;
}

void displayQueue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    
    printf("Queue elements: ");
    if (queue->rear >= queue->front) {
        for (int i = queue->front; i <= queue->rear; i++) {
            printf("%d ", queue->arr[i]);
        }
    } else {
        for (int i = queue->front; i < MAX; i++) {
            printf("%d ", queue->arr[i]);
        }
        for (int i = 0; i <= queue->rear; i++) {
            printf("%d ", queue->arr[i]);
        }
    }
    printf("\n");
}

int main() {
    struct Queue queue;
    int choice, element;
    initializeQueue(&queue);
    
    while (1) {
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &element);
                enqueue(&queue, element);
                break;
            case 2:
                element = dequeue(&queue);
                if (element != -1)
                    printf("Dequeued element: %d\n", element);
                break;
            case 3:
                displayQueue(&queue);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }
    return 0;
}

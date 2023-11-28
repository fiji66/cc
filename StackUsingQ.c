#include <stdio.h>
#include <stdlib.h>

// Define a structure for a queue node
struct QueueNode {
    int data;
    struct QueueNode* next;
};

// Define a structure for a queue
struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

// Initialize a queue
void initializeQueue(struct Queue* queue) {
    queue->front = queue->rear = NULL;
}

// Check if the queue is empty
int isQueueEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

// Enqueue a new element to the rear of the queue
void enqueue(struct Queue* queue, int data) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data = data;
    newNode->next = NULL;

    if (isQueueEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Dequeue an element from the front of the queue
int dequeue(struct Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Error: Queue is empty\n");
        return -1; // Return an error value
    }

    struct QueueNode* temp = queue->front;
    int data = temp->data;

    queue->front = temp->next;
    free(temp);

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    return data;
}

// Define a structure for the stack
struct Stack {
    struct Queue* q1;
    struct Queue* q2;
};

// Initialize a stack
void initializeStack(struct Stack* stack) {
    stack->q1 = (struct Queue*)malloc(sizeof(struct Queue));
    stack->q2 = (struct Queue*)malloc(sizeof(struct Queue));
    initializeQueue(stack->q1);
    initializeQueue(stack->q2);
}

// Push an element onto the stack
void push(struct Stack* stack, int data) {
    if (!isQueueEmpty(stack->q1)) {
        enqueue(stack->q1, data);
    } else {
        enqueue(stack->q2, data);
    }
}

// Pop the top element from the stack
int pop(struct Stack* stack) {
    int dataToPop;

    if (!isQueueEmpty(stack->q1)) {
        while (queueSize(stack->q1) > 1) {
            enqueue(stack->q2, dequeue(stack->q1));
        }
        dataToPop = dequeue(stack->q1);
    } else if (!isQueueEmpty(stack->q2)) {
        while (queueSize(stack->q2) > 1) {
            enqueue(stack->q1, dequeue(stack->q2));
        }
        dataToPop = dequeue(stack->q2);
    } else {
        printf("Error: Stack is empty\n");
        return -1; 
    }

    return dataToPop;
}

int queueSize(struct Queue* queue) {
    int size = 0;
    struct QueueNode* current = queue->front;

    while (current != NULL) {
        size++;
        current = current->next;
    }

    return size;
}

int main() {
    struct Stack stack;
    initializeStack(&stack);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));

    return 0;
}
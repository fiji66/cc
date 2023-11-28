#include <stdio.h>
#include <stdlib.h>

struct StackNode {
    int data;
    struct StackNode* next;
};

struct Stack {
    struct StackNode* top;
};

void initializeStack(struct Stack* stack) {
    stack->top = NULL;
}

int isStackEmpty(struct Stack* stack) {
    return (stack->top == NULL);
}

void push(struct Stack* stack, int data) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(struct Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("Error: Stack is empty\n");
        return -1; 
    }

    struct StackNode* temp = stack->top;
    int data = temp->data;

    stack->top = temp->next;
    free(temp);

    return data;
}

struct Queue {
    struct Stack* stack1;
    struct Stack* stack2;
};

void initializeQueue(struct Queue* queue) {
    queue->stack1 = (struct Stack*)malloc(sizeof(struct Stack));
    queue->stack2 = (struct Stack*)malloc(sizeof(struct Stack));
    initializeStack(queue->stack1);
    initializeStack(queue->stack2);
}

void enqueue(struct Queue* queue, int data) {
    while (!isStackEmpty(queue->stack1)) {
        push(queue->stack2, pop(queue->stack1));
    }

    push(queue->stack1, data);

    while (!isStackEmpty(queue->stack2)) {
        push(queue->stack1, pop(queue->stack2));
    }
}

int dequeue(struct Queue* queue) {
    if (isStackEmpty(queue->stack1)) {
        printf("Error: Queue is empty\n");
        return -1; 
    }

    return pop(queue->stack1);
}

int main() {
    struct Queue queue;
    initializeQueue(&queue);

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);

    printf("Dequeued element: %d\n", dequeue(&queue));
    printf("Dequeued element: %d\n", dequeue(&queue));
    printf("Dequeued element: %d\n", dequeue(&queue));

    return 0;
}
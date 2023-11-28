#include <stdio.h>

#define MAX_SIZE 5

typedef struct {
    int data[MAX_SIZE];
    int front, rear;
} CircularQueue;

void initializeQueue(CircularQueue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isFull(CircularQueue* queue) {
    return (queue->front == (queue->rear + 1) % MAX_SIZE);
}

int isEmpty(CircularQueue* queue) {
    return (queue->front == -1);
}

void enqueue(CircularQueue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue %d.\n", item);
    } else {
        if (isEmpty(queue)) {
            queue->front = 0;
        }
        queue->rear = (queue->rear + 1) % MAX_SIZE;
        queue->data[queue->rear] = item;
        printf("%d enqueued to the queue.\n", item);
    }
}

int dequeue(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;  // Returning -1 to indicate an error or an empty queue
    } else {
        int item = queue->data[queue->front];
        if (queue->front == queue->rear) {
            // Reset the queue after the last element is dequeued
            initializeQueue(queue);
        } else {
            queue->front = (queue->front + 1) % MAX_SIZE;
        }
        printf("%d dequeued from the queue.\n", item);
        return item;
    }
}

void displayQueue(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        int i = queue->front;
        do {
            printf("%d ", queue->data[i]);
            i = (i + 1) % MAX_SIZE;
        } while (i != (queue->rear + 1) % MAX_SIZE);
        printf("\n");
    }
}

int main() {
    CircularQueue myQueue;
    initializeQueue(&myQueue);

    enqueue(&myQueue, 1);
    enqueue(&myQueue, 2);
    enqueue(&myQueue, 3);
    enqueue(&myQueue, 4);
    enqueue(&myQueue, 5);

    displayQueue(&myQueue);

    dequeue(&myQueue);
    dequeue(&myQueue);

    displayQueue(&myQueue);

    enqueue(&myQueue, 6);
    enqueue(&myQueue, 7);

    displayQueue(&myQueue);

    return 0;
}
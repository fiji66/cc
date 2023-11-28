#include <stdio.h>
#include <stdlib.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2

int graph[6][6];

int color[6];
int distance[6];
int parent[6];

int vertices = 6;

struct Queue {
    int capacity;
    int front;
    int rear;
    int *array;
};

struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->array = (int *)malloc(capacity * sizeof(int));
    return queue;
}

void initialize() {
    for (int i = 0; i < vertices; i++) {
        color[i] = 0;
        distance[i] = -1;
    }
}

void enqueue(struct Queue* queue, int vertex) {
    if (queue->rear == queue->capacity - 1) {
        printf("Queue is full\n");
    } 
    else {
        if (queue->front == -1) {
            queue->front = 0;
        }
        queue->rear++;
        queue->array[queue->rear] = vertex;
    }
}

int dequeue(struct Queue* queue) {
    int vertex;
    if (queue->front == -1) {
        printf("Queue is empty.\n");
        return -1;
    } 
    else {
        vertex = queue->array[queue->front];
        queue->front++;
        if (queue->front > queue->rear) {
            queue->front = queue->rear = -1;
        }
        return vertex;
    }
}

void BFS(int source) {
    struct Queue* queue = createQueue(vertices); // ...
    initialize();
    color[source] = 1;
    distance[source] = 0;
    parent[source] = -1;

    enqueue(queue, source); // ...

    while (queue->front != -1) {
        int u = dequeue(queue); // ...
        printf("%d ", u); // Traversal order

        for (int v = 0; v < vertices; v++) {
            if (graph[u][v] == 1 && color[v] == 0) {
                color[v] = 1;
                distance[v] = distance[u] + 1;
                parent[v] = u;
                enqueue(queue, v);
            }
        }
        color[u] = 2;
    }

    free(queue->array); // ...
    free(queue); // ...
}

int main() {
    printf("Input the graph: \n");
    for (int i = 0; i < vertices; i++) { // Step1: Input the graph
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("\n");

    printf("Enter the starting vertex: ");
    int start_vertex; // Step2: Starting vertex
    scanf("%d", &start_vertex);

    BFS(start_vertex); // Step3: BFS call

    for (int i = 0; i < vertices; i++) {   // Step4: Print neighbors
        printf("\n%d : ", i);
        for (int j = 0; j < vertices; j++) {
            if (graph[i][j] == 1) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < vertices; i++) { // Step5: Print parent
        printf("Parent of %d: %d\n", i, parent[i]);
    }

    printf("\n");

    for (int i = 0; i < vertices; i++) { // Step6: Print distance from source
        printf("Distance of %d from %d: %d\n", i, start_vertex, distance[i]);
    }

    return 0;
}
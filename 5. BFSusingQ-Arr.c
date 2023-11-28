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

int queue[6];
int front = -1, rear = -1;

void initialize() {
    for (int i = 0; i < vertices; i++) {
        color[i] = 0;
        distance[i] = -1;
    }
}

void enqueue(int vertex) {
    if (rear == vertices - 1) {
        printf("Queue is full\n");
    } 
    else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = vertex;
    }
}

int dequeue() {
    int vertex;
    if (front == -1) {
        printf("Queue is empty.\n");
        return -1;
    } 
    else {
        vertex = queue[front];
        front++;
        if (front > rear) {
            front = rear = -1;
        }
        return vertex;
    }
}

void BFS(int source) {
    initialize();
    color[source] = 1;
    distance[source] = 0;
    parent[source] = -1;

    enqueue(source);

    while (front != -1) {
        int u = dequeue();
        printf("%d ", u); // Traversal order

        for (int v = 0; v < vertices; v++) {
            if (graph[u][v] == 1 && color[v] == 0) {
                color[v] = 1;
                distance[v] = distance[u] + 1;
                parent[v] = u;
                enqueue(v);
            }
        }
        color[u] = 2;
    }
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

/*
0 1 0 0 1 0
1 0 1 0 1 0
0 1 0 1 0 0
0 0 1 0 1 1
1 1 0 1 0 0
0 0 0 1 0 0
*/
}
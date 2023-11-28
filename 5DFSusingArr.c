#include <stdio.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define NIL -1
#define MAX_VERTICES 100

int time = 0;

int color[MAX_VERTICES];
int pi[MAX_VERTICES];
int d[MAX_VERTICES];
int f[MAX_VERTICES];

int graph[MAX_VERTICES][MAX_VERTICES];

void initializeGraph(int vertices) {
    for (int i = 0; i < vertices; i++) {
        color[i] = WHITE;
        pi[i] = NIL;
        d[i] = 0;
        f[i] = 0;
    }
}

void addEdge(int from, int to) {
    graph[from][to] = 1;
}

void DFS_VISIT(int u, int vertices) {
    time++;
    d[u] = time;
    color[u] = GRAY;
    printf("%d ", u);

    for (int v = 0; v < vertices; v++) {
        if (graph[u][v] == 1 && color[v] == WHITE) {
            pi[v] = u;
            DFS_VISIT(v, vertices);
        }
    }

    time++;
    f[u] = time;
    color[u] = BLACK;
}

void DFS(int vertices) {
    initializeGraph(vertices);

    for (int u = 0; u < vertices; u++) {
        if (color[u] == WHITE) {
            DFS_VISIT(u, vertices);
        }
    }
}

void printDFSResults(int vertices) {
    printf("\n");
    printf("Vertex\tColor\tDiscovery Time\tFinish Time\tParent\n");
    for (int i = 0; i < vertices; i++) {
        printf("%d\t", i);
        if (color[i] == WHITE) {
            printf("WHITE\t");
        } else if (color[i] == GRAY) {
            printf("GRAY\t");
        } else {
            printf("BLACK\t");
        }
        printf("%d\t\t%d\t\t%d\n", d[i], f[i], pi[i]);
    }
}

int main() {
    int num_vertices;
    printf("Enter no. of vertices: ");
    scanf("%d", &num_vertices);

    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int start_vertex;
    scanf("%d", &start_vertex);

    DFS(num_vertices);
    printDFSResults(num_vertices);

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
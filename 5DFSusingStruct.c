#include <stdio.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    int array[MAX_SIZE];
};

void initialize(struct Stack *stack) {
    stack->top = -1;
}

int isEmpty(struct Stack *stack) {
    return (stack->top == -1);
}

int isFull(struct Stack *stack) {
    return (stack->top == MAX_SIZE - 1);
}

void push(struct Stack *stack, int item) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push %d\n", item);
        return;
    }

    stack->top++;
    stack->array[stack->top] = item;
}

int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }

    int item = stack->array[stack->top];
    stack->top--;

    return item;
}

void dfs(int graph[MAX_SIZE][MAX_SIZE], int vertices, int start) {
    struct Stack myStack;
    initialize(&myStack);

    int visited[MAX_SIZE] = {0};

    push(&myStack, start);

    while (!isEmpty(&myStack)) {
        int currentVertex = pop(&myStack);

        if (!visited[currentVertex]) {
            printf("%d ", currentVertex);
            visited[currentVertex] = 1;
        }

        for (int i = vertices - 1; i >= 0; i--) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                push(&myStack, i);
            }
        }
    }
}

int main() {
    int vertices = 6;
    int graph[MAX_SIZE][MAX_SIZE] = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 1, 0},
        {1, 0, 0, 0, 1, 1},
        {0, 1, 0, 0, 0, 0},
        {0, 1, 1, 0, 0, 1},
        {0, 0, 1, 0, 1, 0}
    };

    int startVertex = 0;

    printf("DFS traversal starting from vertex %d: ", startVertex);
    dfs(graph, vertices, startVertex);

    return 0;
}

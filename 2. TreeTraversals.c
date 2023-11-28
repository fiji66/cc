#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Stack {
    int top;
    struct Node* array[100];
};

void initialize(struct Stack* stack) {
    stack->top = -1;
}

int isEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

int isFull(struct Stack* stack) {
    return (stack->top == 99);
}

void push(struct Stack* stack, struct Node* item) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push.\n");
        return;
    }

    stack->top++;
    stack->array[stack->top] = item;
}

struct Node* pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return NULL;
    }

    struct Node* item = stack->array[stack->top];
    stack->top--;

    return item;
}

void Inorder(struct Node* root) {
    if (root == NULL)
        return;
    
    struct Stack myStack;
    initialize(&myStack);

    struct Node* current = root;

    while (current != NULL || !isEmpty(&myStack)) {
        while (current != NULL) {
            push(&myStack, current);
            current = current->left;
        }

        current = pop(&myStack);
        printf("%d ", current->data);

        current = current->right;
    }
}

/*
void PreOrder(struct Node* root) {
    if (root == NULL)
        return;

    struct Stack myStack;
    initialize(&myStack);

    push(&myStack, root);

    while (!isEmpty(&myStack)) {
        struct Node* current = pop(&myStack);
        printf("%d ", current->data);

        if (current->right != NULL)
            push(&myStack, current->right);

        if (current->left != NULL)
            push(&myStack, current->left);
    }
}
*/

/*
void PostOrder(struct Node* root) {
    if (root == NULL)
        return;

    struct Stack myStack1, myStack2;
    initialize(&myStack1);
    initialize(&myStack2);

    push(&myStack1, root);

    while (!isEmpty(&myStack1)) {
        struct Node* current = pop(&myStack1);
        push(&myStack2, current);

        if (current->left != NULL)
            push(&myStack1, current->left);

        if (current->right != NULL)
            push(&myStack1, current->right);
    }

    while (!isEmpty(&myStack2)) {
        struct Node* current = pop(&myStack2);
        printf("%d ", current->data);
    }
}
*/

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Inorder traversal: ");
    Inorder(root);

    return 0;
}
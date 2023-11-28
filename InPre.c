#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to search for a value in inorder array
int search(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

// Recursive function to construct the binary tree
struct TreeNode* buildTreeHelper(int preorder[], int inorder[], int inStart, int inEnd, int* preIndex) {
    // Base case
    if (inStart > inEnd) {
        return NULL;
    }

    // Create a new node with the current value from preorder traversal
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = preorder[*preIndex];
    node->left = NULL;
    node->right = NULL;

    // Increment the index for the next recursive call
    (*preIndex)++;

    // If the current subtree has only one element, return the node
    if (inStart == inEnd) {
        return node;
    }

    // Find the index of the current node's value in inorder traversal
    int inIndex = search(inorder, inStart, inEnd, node->val);

    // Recursively build the left and right subtrees
    node->left = buildTreeHelper(preorder, inorder, inStart, inIndex - 1, preIndex);
    node->right = buildTreeHelper(preorder, inorder, inIndex + 1, inEnd, preIndex);

    return node;
}

// Function to construct the binary tree
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    int preIndex = 0;
    return buildTreeHelper(preorder, inorder, 0, inorderSize - 1, &preIndex);
}

// Function to print inorder traversal of the tree
void printInorder(struct TreeNode* root) {
    if (root != NULL) {
        printInorder(root->left);
        printf("%d ", root->val);
        printInorder(root->right);
    }
}

int main() {
    int preorder[] = {3, 9, 20, 15, 7};
    int inorder[] = {9, 3, 15, 20, 7};

    int preorderSize = sizeof(preorder) / sizeof(preorder[0]);
    int inorderSize = sizeof(inorder) / sizeof(inorder[0]);

    struct TreeNode* root = buildTree(preorder, preorderSize, inorder, inorderSize);

    printf("Inorder traversal of the constructed tree: ");
    printInorder(root);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to search for the index of a value in the inorder array.
int search(int arr[], int start, int end, int value) {
    int i;
    for (i = start; i <= end; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

// Recursive function to construct a binary tree from inorder and postorder traversals.
struct TreeNode* buildTreeHelper(int* inorder, int inStart, int inEnd, int* postorder, int postStart, int postEnd) {
    if (inStart > inEnd || postStart > postEnd) {
        return NULL;
    }

    // The last element in postorder is the root of the current subtree.
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = postorder[postEnd];

    // Find the index of the root in inorder.
    int rootIndex = search(inorder, inStart, inEnd, root->val);

    // Recursively build the right and left subtrees.
    root->right = buildTreeHelper(inorder, rootIndex + 1, inEnd, postorder, postStart + rootIndex - inStart, postEnd - 1);
    root->left = buildTreeHelper(inorder, inStart, rootIndex - 1, postorder, postStart, postStart + rootIndex - inStart - 1);

    return root;
}

// Function to build a binary tree from inorder and postorder traversals.
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    if (inorderSize != postorderSize || inorderSize == 0) {
        return NULL;
    }

    return buildTreeHelper(inorder, 0, inorderSize - 1, postorder, 0, postorderSize - 1);
}

// Function to print inorder traversal of a binary tree.
void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->val);
        inorderTraversal(root->right);
    }
}

int main() {
    int inorder[] = {9, 3, 15, 20, 7};
    int postorder[] = {9, 15, 7, 20, 3};
    
    int inorderSize = sizeof(inorder) / sizeof(inorder[0]);
    int postorderSize = sizeof(postorder) / sizeof(postorder[0]);

    struct TreeNode* root = buildTree(inorder, inorderSize, postorder, postorderSize);

    printf("Inorder traversal of the constructed tree: ");
    inorderTraversal(root);

    return 0;
}
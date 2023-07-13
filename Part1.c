#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* insert(struct TreeNode* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->val) {
        root->left = insert(root->left, value);
    } else if (value > root->val) {
        root->right = insert(root->right, value);
    }

    return root;
}

int closestValue(struct TreeNode* root, double target) {
    int closest = root->val;
    struct TreeNode* current = root;

    while (current != NULL) {
        if (fabs(target - current->val) < fabs(target - closest)) {
            closest = current->val;
        }

        if (target < current->val) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    return closest;
}

int main() {
    struct TreeNode* root = NULL;
    int value;
    double target;

    // Read the BST values from the user until a non-numeric input is given
    printf("Enter the values for the BST (non-numeric input to stop):\n");
    while (scanf("%d", &value) == 1) {
        root = insert(root, value);
    }

    // Clear the input buffer
    while (getchar() != '\n');

    // Read the target value from the user
    printf("Enter the target value: ");
    scanf("%lf", &target);

    // Find the closest value and print the result
    int closest = closestValue(root, target);
    printf("Closest number = %d\n", closest);

    return 0;
}

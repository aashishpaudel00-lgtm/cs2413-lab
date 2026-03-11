#include <stdbool.h>
#include <stddef.h>
#include <limits.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

static int checkHeight(struct TreeNode* node) {
    if (node == NULL) return 0;

    int left = checkHeight(node->left);
    if (left == -1) return -1;

    int right = checkHeight(node->right);
    if (right == -1) return -1;

    int diff = left - right;
    if (diff > 1 || diff < -1) return -1;

    return (left > right ? left : right) + 1;
}

static bool isBST(struct TreeNode* node, long long min, long long max) {
    if (node == NULL) return true;
    if (node->val <= min || node->val >= max) return false;

    return isBST(node->left, min, node->val) &&
           isBST(node->right, node->val, max);
}

bool isAVL(struct TreeNode* root) {
    if (root == NULL) return true;
    if (!isBST(root, LLONG_MIN, LLONG_MAX)) return false;
    if (checkHeight(root) == -1) return false;
    return true;
}
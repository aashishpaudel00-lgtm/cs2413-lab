#include <stddef.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* bstSearch(struct TreeNode* root, int target) {
    if (root == NULL || root->val == target)
        return root;
    
    if (target < root->val)
        return bstSearch(root->left, target);
    else
        return bstSearch(root->right, target);
}
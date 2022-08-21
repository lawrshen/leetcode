#include <stdlib.h>

/**
 * Definition for a binary tree node.
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// AB Tree

bool isSubStructure(TreeNode *A, TreeNode *B);
bool checkSubTree(TreeNode *t1, TreeNode *t2);
TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2);

// Single Tree

int maxDepth(TreeNode *root);
int diameterOfBinaryTree(TreeNode *root);
int maxPathSum(TreeNode *root);

// Build Tree

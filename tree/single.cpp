#include "tree.h"
#include <algorithm>
#include <limits.h>
#include <vector>
using namespace std;

int maxDepth(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }
    int leftDepth = maxDepth(root->left),
        rightDepth = maxDepth(root->right);
    return max(leftDepth, rightDepth) + 1;
}

int diameter = 0;
int depth(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }
    int leftDepth = depth(root->left),
        rightDepth = depth(root->right);
    diameter = max(diameter, leftDepth + rightDepth);
    return max(leftDepth, rightDepth) + 1;
}

// 543 https://leetcode.cn/problems/diameter-of-binary-tree/
int diameterOfBinaryTree(TreeNode *root) {
    depth(root);
    return diameter;
}

int max_path_sum = INT_MIN;
int pathSum(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }
    int leftSum = max(pathSum(root->left), 0),
        rightSum = max(pathSum(root->right), 0);
    max_path_sum = max(max_path_sum, leftSum + rightSum + root->val);
    return max(leftSum, rightSum) + root->val;
}

// 124 https://leetcode.cn/problems/binary-tree-maximum-path-sum/
int maxPathSum(TreeNode *root) {
    pathSum(root);
    return max_path_sum;
}

int height(TreeNode *root) {
    if (!root) {
        return 0;
    }
    int l = height(root->left), r = height(root->right);
    if (l == -1 || r == -1 || abs(l - r) > 1) {
        return -1;
    }
    return max(l, r) + 1;
}

// 110 https://leetcode.cn/problems/balanced-binary-tree/

bool isBalanced(TreeNode *root) {
    return height(root) != -1;
}

// 226 https://leetcode.cn/problems/invert-binary-tree/
// offer27 https://leetcode.cn/problems/er-cha-shu-de-jing-xiang-lcof/
TreeNode *invertTree(TreeNode *root) {
    if (!root)
        return {};
    TreeNode *leftNode = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(leftNode);
    return root;
}

void pathDfs(TreeNode *root, int sum, vector<int> &tmp, vector<vector<int>> &res) {
    if (root == nullptr)
        return;
    tmp.emplace_back(root->val);
    if (root->left == nullptr && root->right == nullptr) {
        if (sum == root->val) {
            res.emplace_back(tmp);
        }
    }
    pathDfs(root->left, sum - root->val, tmp, res);
    pathDfs(root->right, sum - root->val, tmp, res);
    tmp.pop_back();
}

// 113 https://leetcode.cn/problems/path-sum-ii/
vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
    vector<int> tmp;
    vector<vector<int>> res;
    pathDfs(root, targetSum, tmp, res);
    return res;
}

// 114 https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/
TreeNode *last = nullptr;
void flatten(TreeNode *root) {
    if (root == nullptr)
        return;
    flatten(root->right);
    flatten(root->left);
    root->right = last;
    root->left = nullptr;
    last = root;
}
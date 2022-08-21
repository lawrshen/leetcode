#include "tree.h"
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

// 105 https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    if (preorder.empty())
        return nullptr;
    int val = preorder[0];
    TreeNode *root = new TreeNode(val);
    auto iter = find(inorder.begin(), inorder.end(), val);
    vector<int> pl(preorder.begin() + 1, preorder.begin() + 1 + (iter - inorder.begin())),
        pr(preorder.begin() + 1 + (iter - inorder.begin()), preorder.end()),
        il(inorder.begin(), iter),
        ir(iter + 1, inorder.end());
    root->left = buildTree(pl, il);
    root->right = buildTree(pr, ir);
    return root;
}

// 144 https://leetcode.cn/problems/binary-tree-preorder-traversal/
vector<int> preorderTraversal(TreeNode *root) {
    vector<int> res;
    stack<TreeNode *> stk;
    stk.emplace(root);
    while (!stk.empty()) {
        TreeNode *node = stk.top();
        stk.pop();
        if (node) {
            res.emplace_back(node->val);
            stk.emplace(node->right);
            stk.emplace(node->left);
        }
    }
    return res;
}
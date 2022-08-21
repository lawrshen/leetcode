#include "tree.h"

// helper of isSubStructure, B same as root of A
bool recur(TreeNode *A, TreeNode *B) {
    if (B == NULL) // B is traversed completely
        return true;
    if (A == NULL || A->val != B->val)
        return false;
    return recur(A->left, B->left) && recur(A->right, B->right);
}

// check whether B is a subStructure of A, nullptr is not a subStructure of any tree
bool isSubStructure(TreeNode *A, TreeNode *B) {
    if (!A || !B)
        return false;
    return recur(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
}

// https://leetcode.cn/problems/check-subtree-lcci/submissions/
bool checkSubTree(TreeNode *t1, TreeNode *t2) {
    if (t2 == nullptr) {
        return true;
    }
    if (t1 == nullptr) {
        return false;
    }
    if (t1->val == t2->val) {
        if (checkSubTree(t1->left, t2->left) &&
            checkSubTree(t1->right, t2->right))
            return true;
    }
    if (checkSubTree(t1->left, t2) ||
        checkSubTree(t1->right, t2))
        return true;
    return false;
}

// 617 https://leetcode.cn/problems/merge-two-binary-trees/
TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
    if (root1 == nullptr)
        return root2;
    if (root2 == nullptr)
        return root1;
    if (root1 && root2)
        root1->val += root2->val;
    root1->left = mergeTrees(root1->left, root2->left);
    root1->right = mergeTrees(root1->right, root2->right);
    return root1;
}
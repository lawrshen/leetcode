#include "tree.h"

typedef TreeNode Node;

void toDoublyList(Node *root, Node *&last) {
    if (root == nullptr) {
        return;
    }
    toDoublyList(root->left, last);
    root->left = last;
    if (last != nullptr) {
        last->right = root;
    }
    last = root;
    if (root->right) {
        toDoublyList(root->right, last);
    }
}

// Offer 36 https://leetcode.cn/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/
Node *treeToDoublyList(Node *root) {
    if (root == nullptr)
        return {};
    Node *last = nullptr;
    toDoublyList(root, last);
    Node *head = root;
    while (head->left != nullptr) {
        head = head->left;
    }
    last->right = head;
    head->left = last;
    return head;
}

Node *doublyListLast = nullptr;
Node *convertBST(Node *root) {
    if (!root)
        return nullptr;
    if (root->right) {
        Node *right = convertBST(root->right);
        root->right = right;
        right->left = root;
    }
    if (!doublyListLast) {
        doublyListLast = root;
    }
    Node *p = root->left;
    if (p) {
        Node *left = convertBST(root->left);
        while (p->right) {
            p = p->right;
        }
        p->right = root;
        root->left = p;
        return left;
    } else {
        return root;
    }
}
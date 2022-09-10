#include <limits.h>
#include <stack>
#include <vector>
using namespace std;

// offer 33 https://leetcode.cn/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/
bool verifyPostorder(vector<int> &postorder) {
    // 1 3 2 6 5 left->right->root left<root<right
    stack<int> incStk;
    int preElem = INT_MAX;
    int n = postorder.size();
    for (int i = n - 1; i >= 0; i--) {
        if (postorder[i] > preElem) {
            return false;
        }
        while (!incStk.empty() && incStk.top() > postorder[i]) {
            preElem = incStk.top();
            incStk.pop();
        }
        incStk.push(postorder[i]);
    }
    return true;
}

bool verifyPostorderRecur(vector<int> &postorder, int left, int right) {
    if (left >= right)
        return true;
    int i = left;
    while (postorder[i] < postorder[right])
        i++;
    int j = i;
    while (postorder[i] > postorder[right])
        i++;
    return i == right && verifyPostorderRecur(postorder, left, j - 1) && verifyPostorderRecur(postorder, j, right - 1);
}
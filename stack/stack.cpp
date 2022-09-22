#include <limits.h>
#include <stack>
#include <string>
#include <vector>
using namespace std;

// 456 https://leetcode.cn/problems/132-pattern/
bool find132pattern(vector<int> &nums) {
    // 固定 a[j],a[j]的左边找到一个数比它小的数a[i],
    // 右边找到一个比它小的数a[k],满足a[i]<a[k].
    // 那么我们可以挑选a[j]左边的最小值和a[j]右边的最大值
    // （前提都需要小于a[j]）作为a[i]和a[k]进行比较。
    if (nums.size() < 3)
        return false;
    int n = nums.size();
    vector<int> leftMin(n);
    leftMin[0] = INT_MAX;
    for (int i = 1; i < n; i++) {
        leftMin[i] = min(leftMin[i - 1], nums[i - 1]);
    }
    stack<int> rightMaxLess;
    int maxnum = INT_MIN;
    for (int i = n - 1; i > 0; i--) {
        if (nums[i] > leftMin[i]) {
            while (!rightMaxLess.empty() && nums[i] > rightMaxLess.top()) {
                maxnum = rightMaxLess.top();
                rightMaxLess.pop();
            }
            if (maxnum > leftMin[i]) {
                return true;
            }
        }
        // 当循环到 nums[i] 时先将其与栈顶的数比较，如果栈空或者比栈顶的数小便将其压栈
        // 栈本身是自顶到底递增的
        rightMaxLess.emplace(nums[i]);
    }
    return false;
}

// 739 https://leetcode.cn/problems/daily-temperatures/
vector<int> dailyTemperatures(vector<int> &temperatures) {
    int n = temperatures.size();
    vector<int> res(n);
    stack<int> stk;
    for (int i = n - 1; i >= 0; i--) {
        while (!stk.empty() && temperatures[stk.top()] <= temperatures[i]) {
            stk.pop();
        }
        res[i] = stk.empty() ? 0 : stk.top() - i;
        stk.emplace(i);
    }
    return res;
}
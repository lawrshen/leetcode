#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

// 239 https://leetcode.cn/problems/sliding-window-maximum/
// offer 59 https://leetcode.cn/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof/

vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    deque<int> dq;
    for (int i = 0; i < k; i++) {
        while (!dq.empty() && nums[i] >= nums[dq.back()]) {
            dq.pop_back();
        }
        dq.emplace_back(i);
    }
    int n = nums.size();
    vector<int> res = {nums[dq.front()]};
    for (int i = k; i < n; i++) {
        while (!dq.empty() && nums[i] >= nums[dq.back()]) {
            dq.pop_back();
        }
        dq.emplace_back(i);
        while (dq.front() <= i - k) {
            dq.pop_front();
        }
        res.emplace_back(nums[dq.front()]);
    }
    return res;
}
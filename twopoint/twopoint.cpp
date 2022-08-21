#include <algorithm>
#include <limits.h>
#include <vector>
using namespace std;

// 27 https://leetcode.cn/problems/remove-element/
int removeElement(vector<int> &nums, int val) {
    int n = nums.size(), len = 0, idx = 0;
    while (idx < n) {
        if (nums[idx] != val) {
            nums[len++] = nums[idx];
        }
        idx++;
    }
    return len;
}

// 283 https://leetcode.cn/problems/move-zeroes/
void moveZeroes(vector<int> &nums) {
    int n = nums.size(), len = 0, idx = 0;
    while (idx < n) {
        if (nums[idx] != 0) {
            nums[len++] = nums[idx];
        }
        idx++;
    }
    while (len < n) {
        nums[len++] = 0;
    }
}

// 977 https://leetcode.cn/problems/squares-of-a-sorted-array/
vector<int> sortedSquares(vector<int> &nums) {
    int n = nums.size();
    vector<int> res(n);
    int l = 0, r = n - 1;
    int k = n - 1;
    while (l < r) {
        if (abs(nums[l]) > nums[r]) {
            res[k--] = nums[l] * nums[l];
            l++;
        } else {
            res[k--] = nums[r] * nums[r];
            r--;
        }
    }
    res[0] = nums[l] * nums[l];
    return res;
}

// 209 https://leetcode.cn/problems/minimum-size-subarray-sum/
int minSubArrayLen(int target, vector<int> &nums) {
    int n = nums.size(), l = 0;
    int sum = 0, res = INT_MAX;
    for (int r = 0; r < n; r++) {
        sum += nums[r];
        while (sum - nums[l] >= target) {
            sum -= nums[l++];
        }
        if (sum >= target) {
            res = min(res, r - l + 1);
        }
    }
    return res == INT_MAX ? 0 : res;
}
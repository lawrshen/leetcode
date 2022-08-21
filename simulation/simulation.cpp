#include <algorithm>
#include <vector>
using namespace std;

// 31 https://leetcode.cn/problems/next-permutation/
void nextPermutation(vector<int> &nums) {
    int n = nums.size();
    int i = n - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }
    if (i >= 0) {
        int j = n - 1;
        while (j > i && nums[j] <= nums[i]) {
            j--;
        }
        swap(nums[i], nums[j]);
    }
    reverse(nums.begin() + i + 1, nums.end());
}

// 59 https://leetcode.cn/problems/spiral-matrix-ii/
vector<vector<int>> generateMatrix(int n) {
    int top = 0, button = n - 1, left = 0, right = n - 1;
    vector<vector<int>> res(n, vector<int>(n));
    int k = 1;
    while (k <= n * n) {
        for (int i = left; i <= right; i++, k++) {
            res[top][i] = k;
        }
        top++;
        for (int i = top; i <= button; i++, k++) {
            res[i][right] = k;
        }
        right--;
        for (int i = right; i >= left; i--, k++) {
            res[button][i] = k;
        }
        button--;
        for (int i = button; i >= top; i--, k++) {
            res[i][left] = k;
        }
        left++;
    }
    return res;
}

// 845 https://leetcode.cn/problems/longest-mountain-in-array/
int longestMountain(vector<int> &arr) {
    int n = arr.size(), l = 0, res = 0;
    while (l + 2 < n) {
        int r = l + 1;
        if (arr[l] < arr[l + 1]) {
            while (r + 1 < n && arr[r] < arr[r + 1]) {
                r++;
            }
            if (r < n - 1 && arr[r] > arr[r + 1]) {
                while (r < n - 1 && arr[r] > arr[r + 1]) {
                    r++;
                }
                res = max(res, r - l + 1);
            } else {
                r++;
            }
        }
        l = r;
    }
    return res;
}
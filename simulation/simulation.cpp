#include <algorithm>
#include <string>
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

// 54 https://leetcode.cn/problems/spiral-matrix/
vector<int> spiralOrder(vector<vector<int>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<int> res(m * n);
    int top = 0, button = m - 1, left = 0, right = n - 1;
    int i = 0;
    while (i < m * n) {
        for (int j = left; j <= right; j++) {
            res[i++] = matrix[top][j];
        }
        if (i == m * n)
            break;
        top++;
        for (int j = top; j <= button; j++) {
            res[i++] = matrix[j][right];
        }
        if (i == m * n)
            break;
        right--;
        for (int j = right; j >= left; j--) {
            res[i++] = matrix[button][j];
        }
        if (i == m * n)
            break;
        button--;
        for (int j = button; j >= top; j--) {
            res[i++] = matrix[j][left];
        }
        if (i == m * n)
            break;
        left++;
    }
    return res;
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

// 56 https://leetcode.cn/problems/merge-intervals/
vector<vector<int>> merge(vector<vector<int>> &intervals) {
    if (intervals.empty())
        return {};
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged;
    for (int i = 0; i < intervals.size(); i++) {
        int l = intervals[i][0], r = intervals[i][1];
        if (merged.empty() || merged.back()[1] < l) {
            merged.push_back({l, r});
        } else {
            merged.back()[1] = max(merged.back()[1], r);
        }
    }
    return merged;
}

// 57 https://leetcode.cn/problems/insert-interval/
vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
    vector<vector<int>> res;
    int l = newInterval[0], r = newInterval[1];
    bool place = false;
    for (auto &interval : intervals) {
        if (interval[0] > r) {
            if (!place) {
                res.push_back({l, r});
                place = true;
            }
            res.push_back(interval);
        } else if (interval[1] < l) {
            res.push_back(interval);
        } else {
            l = min(l, interval[0]);
            r = max(r, interval[1]);
        }
    }
    if (!place) {
        res.push_back({l, r});
    }
    return res;
}

// 58 https://leetcode.cn/problems/length-of-last-word/
int lengthOfLastWord(string s) {
    int i = s.size() - 1;
    int cnt = 0;
    while (i >= 0 && s[i] == ' ')
        i--;
    while (i >= 0 && ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))) {
        cnt++;
        i--;
    }
    return cnt;
}

// 66 https://leetcode.cn/problems/plus-one/
vector<int> plusOne(vector<int> &digits) {
    int n = digits.size();
    for (int i = n - 1; i >= 0; i--) {
        digits[i] = (digits[i] + 1) % 10;
        if (digits[i] != 0) {
            return digits;
        }
    }
    vector<int> res(n + 1);
    res[0] = 1;
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

// 151 https://leetcode.cn/problems/reverse-words-in-a-string/
// offer 58 https://leetcode.cn/problems/fan-zhuan-dan-ci-shun-xu-lcof/
string reverseWords(string s) {
    string res = "";
    int i = s.size() - 1;
    while (i >= 0) {
        string tmp = "";
        while (i >= 0 && s[i] == ' ')
            i--;
        while (i >= 0 && s[i] != ' ') {
            tmp = s[i--] + tmp;
        }
        if (!tmp.empty())
            res += tmp + " ";
    }
    res.pop_back();
    return res;
}

// 189 https://leetcode.cn/problems/rotate-array/
void rotate(vector<int> &nums, int k) {
    k %= nums.size();
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}

// 504 https://leetcode.cn/problems/base-7/
string convertToBase7(int num) {
    string res = "";
    bool negative = num < 0;
    num = abs(num);
    do {
        res.push_back(num % 7 + '0');
        num /= 7;
    } while (num > 0);
    reverse(res.begin(), res.end());
    if (negative)
        res = "-" + res;
    return res;
}

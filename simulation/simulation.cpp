#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
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
// https://www.nowcoder.com/discuss/816927
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

// offer 58 https://leetcode.cn/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/
string reverseLeftWords(string s, int n) {
    n %= s.length();
    return s.substr(n, s.length() - n) + s.substr(0, n);
}

// 950 https://leetcode.cn/problems/reveal-cards-in-increasing-order/
vector<int> deckRevealedIncreasing(vector<int> &deck) {
    sort(deck.begin(), deck.end(), [](int &a, int &b) {
        return a > b;
    });
    deque<int> dq;
    for (int &d : deck) {
        if (dq.size() < 2) {
            dq.push_front(d);
        } else {
            dq.push_front(dq.back());
            dq.push_front(d);
            dq.pop_back();
        }
    }
    return vector<int>(dq.begin(), dq.end());
}

// interview-13 https://leetcode.cn/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/
int getSum(int x) {
    int res = 0;
    while (x) {
        res += x % 10;
        x /= 10;
    }
    return res;
}

int movingCount(int m, int n, int k) {
    int res = 1;
    vector<vector<bool>> dp(m, vector<bool>(n));
    dp[0][0] = k >= 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if ((i == 0 && j == 0) || (getSum(i) + getSum(j) > k)) {
                continue;
            }
            if (i > 0) {
                dp[i][j] = dp[i][j] || dp[i - 1][j];
            }
            if (j > 0) {
                dp[i][j] = dp[i][j] || dp[i][j - 1];
            }
            if (dp[i][j]) {
                res++;
            }
        }
    }
    return res;
}

// offer 66 https://leetcode.cn/problems/gou-jian-cheng-ji-shu-zu-lcof/
vector<int> constructArr(vector<int> &a) {
    int n = a.size();
    vector<int> l(n, 1), r(n, 1), b(n, 1);
    for (int i = 1; i < n; i++) {
        l[i] = l[i - 1] * a[i - 1];
        r[n - 1 - i] = r[n - i] * a[n - i];
    }
    b[0] = r[0], b[n - 1] = l[n - 1];
    for (int i = 1; i < n - 1; i++) {
        b[i] = l[i] * r[i];
    }
    return b;
}

// offer 60 https://leetcode.cn/problems/nge-tou-zi-de-dian-shu-lcof/
vector<double> dicesProbability(int n) {
    vector<double> dp(6, 1.0 / 6.0);
    for (int i = 2; i <= n; i++) {
        // i dice range [1*i,6*i] len = 5*i+1
        vector<double> tmp(5 * i + 1, 0);
        for (int j = 0; j < dp.size(); j++) {
            for (int k = 0; k < 6; k++) {
                tmp[j + k] += dp[j] / 6.0;
            }
        }
        dp = tmp;
    }
    return dp;
}

// 946 https://leetcode.cn/problems/validate-stack-sequences/
// offer 31 https://leetcode.cn/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof/
bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
    stack<int> stk;
    int i = 0;
    for (int &num : pushed) {
        stk.push(num);
        while (!stk.empty() && stk.top() == popped[i]) {
            stk.pop();
            i++;
        }
    }
    return stk.empty();
}

// 400 https://leetcode.cn/problems/nth-digit/
// offer 44 https://leetcode.cn/problems/shu-zi-xu-lie-zhong-mou-yi-wei-de-shu-zi-lcof/
int findNthDigit(int n) {
    int len = 1;
    long start = 1, cnt = 9;
    while (cnt < n) {
        n -= cnt;
        len++;
        start *= 10;
        cnt = 9 * start * len;
    }
    return to_string(start + (n - 1) / len)[(n - 1) % len] - '0';
}

// offer 45 https://leetcode.cn/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof/
string minNumber(vector<int> &nums) {
    sort(nums.begin(), nums.end(), [](int &a, int &b) {
        return to_string(a) + to_string(b) < to_string(b) + to_string(a);
    });
    string res = "";
    for (int &n : nums) {
        res += to_string(n);
    }
    return res;
}

// 667 https://leetcode.cn/problems/beautiful-arrangement-ii/
vector<int> constructArray(int n, int k) {
    vector<int> res;
    for (int i = 1; i < n - k; i++) {
        res.emplace_back(i);
    }
    for (int i = n - k, j = n; i <= j; i++, j--) {
        res.emplace_back(i);
        if (i != j) {
            res.emplace_back(j);
        }
    }
    return res;
}
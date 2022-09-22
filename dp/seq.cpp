#include <algorithm>
#include <cstring>
#include <set>
#include <string>
#include <vector>
using namespace std;

// 115 https://leetcode.cn/problems/distinct-subsequences/
int numDistinct(string s, string t) {
    size_t m = s.length(), n = t.length();
    vector<vector<unsigned int>> dp(m + 1, vector<unsigned int>(n + 1, 0));
    for (int i = 0; i <= m; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[m][n];
}

// 926 https://leetcode.cn/problems/flip-string-to-monotone-increasing/
// offer92 https://leetcode.cn/problems/cyJERH/
int minFlipsMonoIncr(string s) {
    int dp0[2] = {0, 0}, dp1[2] = {0, 0};
    for (char &ch : s) {
        dp0[1] = dp0[0] + (ch == '1');
        dp1[1] = min(dp0[0], dp1[0]) + (ch == '0');
        dp0[0] = dp0[1];
        dp1[0] = dp1[1];
    }
    return min(dp0[0], dp1[0]);
}

// 647 https://leetcode.cn/problems/palindromic-substrings/
int countSubstrings(string s) {
    int n = s.size();
    int cnt = 0;
    vector<vector<bool>> dp(n, vector<bool>(n));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            if (s[i] == s[j]) {
                if (j - i <= 1 || dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    cnt++;
                }
            }
        }
    }
    return cnt;
}

// 72 https://leetcode.cn/problems/edit-distance/
int minDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; i++) {
        dp[i][0] = i;
    }
    for (int j = 1; j <= n; j++) {
        dp[0][j] = j;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = min(dp[i - 1][j - 1] + (word1[i - 1] != word2[j - 1]), min(dp[i - 1][j], dp[i][j - 1]) + 1);
        }
    }
    return dp[m][n];
}

// 139 https://leetcode.cn/problems/word-break/
bool wordBreak(string s, vector<string> &wordDict) {
    int n = s.size();
    vector<bool> dp(n + 1);
    set<string> wordDictSet(wordDict.begin(), wordDict.end());
    dp[0] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] && wordDictSet.count(s.substr(j, i - j))) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
}

// offer 46 https://leetcode.cn/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof/
int translateNum(int num) {
    string tmp = to_string(num);
    int n = tmp.size();
    vector<int> dp(n);
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        dp[i] = dp[i - 1];
        int n = (tmp[i - 1] - '0') * 10 + (tmp[i] - '0');
        if (n > 9 && n < 26) {
            if (i == 1)
                dp[i]++;
            else
                dp[i] += dp[i - 2];
        }
    }
    return dp[n - 1];
}

// 300 https://leetcode.cn/problems/longest-increasing-subsequence/
int lengthOfLIS(vector<int> &nums) {
}

int rob(vector<int> &arr) {
    int n = arr.size();
    int first = arr[0], second = max(arr[0], arr[1]);
    for (int i = 2; i < n; i++) {
        int tmp = second;
        second = max(arr[i] + first, second);
        first = tmp;
    }
    return second;
}

// 740 https://leetcode.cn/problems/delete-and-earn/
int deleteAndEarn(vector<int> &nums) {
    int maxVal = *max_element(nums.begin(), nums.end());
    vector<int> arr(maxVal + 1);
    for (int num : nums) {
        arr[num] += num;
    }
    return rob(arr);
}
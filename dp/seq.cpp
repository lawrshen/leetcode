#include <cstring>
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

#include <algorithm>
#include <vector>
using namespace std;

// 221 https://leetcode.cn/problems/maximal-square/
int maximalSquare(vector<vector<char>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n));
    int res = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = matrix[i][j] == '1' ? 1 : 0;
            } else if (matrix[i][j] == '1') {
                dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
            }
            res = max(res, dp[i][j]);
        }
    }
    return res * res;
}
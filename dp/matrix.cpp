#include <algorithm>
#include <limits.h>
#include <numeric>
#include <vector>
using namespace std;

// 85 https://leetcode.cn/problems/maximal-rectangle/
int maximalRectangle(vector<vector<char>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> left(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == '1') {
                left[i][j] = j == 0 ? 1 : left[i][j - 1] + 1;
            }
        }
    }
    int res = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == '0') {
                continue;
            }
            int width = left[i][j];
            int area = width;
            for (int k = i - 1; k >= 0; k--) {
                width = min(width, left[k][j]);
                area = max(area, (i - k + 1) * width);
            }
            res = max(res, area);
        }
    }
    return res;
}

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

// 541 https://leetcode.cn/problems/01-matrix/
vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> dp(m, vector<int>(n, INT_MAX - 1));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 0) {
                dp[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i > 0) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
            }
            if (j > 0) {
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
            }
        }
    }
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (i < m - 1) {
                dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
            }
            if (j < n - 1) {
                dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
            }
        }
    }
    return dp;
}
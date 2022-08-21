#include <limits.h>
#include <vector>
using namespace std;

// 322 https://leetcode.cn/problems/coin-change/comments/
int coinChange(vector<int> &coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
        for (int &c : coins) {
            if (c > i || dp[i - c] == INT_MAX) {
                continue;
            }
            dp[i] = min(dp[i], dp[i - c] + 1);
        }
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

// 403 https://leetcode.cn/problems/frog-jump/
bool canCross(vector<int> &stones) {
    int n = stones.size();
    vector<vector<int>> dp(n, vector<int>(n));
    
}
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

// 135 https://leetcode.cn/problems/candy/
int candy(vector<int> &ratings) {
    int n = ratings.size();
    vector<int> candy(n, 1);
    for (int i = 1; i < n; i++) {
        if (ratings[i] > ratings[i - 1]) {
            candy[i] = candy[i - 1] + 1;
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1]) {
            candy[i] = max(candy[i], candy[i + 1] + 1);
        }
    }
    return accumulate(candy.begin(), candy.end(), 0);
}

// 55 https://leetcode.cn/problems/jump-game/
bool canJump(vector<int> &nums) {
    int n = nums.size();
    int rightmost = 0;
    for (int i = 0; i < n; i++) {
        if (i <= rightmost) {
            rightmost = max(rightmost, i + nums[i]);
            if (rightmost >= n - 1)
                return true;
        } else {
            break;
        }
    }
    return false;
}
#include <string>
#include <vector>
using namespace std;

// 60 https://leetcode.cn/problems/permutation-sequence/
string getPermutation(int n, int k) {
    vector<int> factorial(n, 1);
    for (int i = 1; i < n; i++) {
        factorial[i] = factorial[i - 1] * i;
    }
    string res = "";
    vector<int> vaild(n + 1, 1);
    k--;
    for (int i = 1; i <= n; ++i) {
        int order = k / factorial[n - i] + 1;
        for (int j = 1; j <= n; j++) {
            order -= vaild[j];
            if (!order) {
                res += (j + '0');
                vaild[j] = 0;
                break;
            }
        }
        k %= factorial[n - i];
    }
    return res;
}
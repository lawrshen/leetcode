#include <vector>
using namespace std;

// offer56-I https://leetcode.cn/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/
vector<int> singleNumbers(vector<int> &nums) {
    int ret = 0;
    for (int &n : nums) {
        ret ^= n;
    }
    int div = 1;
    while (!(div & ret)) {
        div <<= 1;
    }
    int a = 0, b = 0;
    for (int &n : nums) {
        if (div & n) {
            a ^= n;
        } else {
            b ^= n;
        }
    }
    return {a, b};
}
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

// 1545 https://leetcode.cn/problems/find-kth-bit-in-nth-binary-string/
char findKthBit(int n, int k) {
    if (k == 1)
        return '0';
    int mid = 1 << (n - 1);
    if (k < mid)
        return findKthBit(n - 1, k);
    else if (k == mid)
        return '1';
    else
        return findKthBit(n - 1, 2 * mid - k) == '0' ? '1' : '0';
}
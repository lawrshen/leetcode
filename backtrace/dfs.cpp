#include <algorithm>
#include <vector>
using namespace std;

// 386 https://leetcode.cn/problems/lexicographical-numbers/
vector<int> lexicalOrder(int n) {
    vector<int> ret(n);
    int number = 1;
    for (int i = 0; i < n; i++) {
        ret[i] = number;
        if (number * 10 <= n) {
            number *= 10;
        } else {
            while (number % 10 == 9 || number + 1 > n) {
                number /= 10;
            }
            number++;
        }
    }
    return ret;
}

// 440 https://leetcode.cn/problems/k-th-smallest-in-lexicographical-order/
int findKthNumber(int n, int k) {
    int cur = 1;
    k--;
    while (k > 0) {
        long step = 0, first = cur, last = cur + 1;
        while (first <= n) {
            step += min((long)n + 1, last) - first;
            first *= 10;
            last *= 10;
        }
        if (step <= k) {
            cur++;
            k -= step;
        } else {
            cur *= 10;
            k--;
        }
    }
    return cur;
}

int intCount(int n, int m) {
    if (n == 1 || m == 1) {
        return 1;
    } else if (n < m) {
        return intCount(n, n);
    } else if (n == m) {
        return intCount(n, n - 1);
    } else {
        return intCount(n, m - 1) + intCount(n - m, m);
    }
}

// Integer division
int IntegerDivision(int n) {
    return intCount(n, n);
}
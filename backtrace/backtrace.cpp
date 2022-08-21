#include <string>
#include <vector>
using namespace std;

void combinationDFS(vector<int> &candidates, int target, int idx, int sum, vector<int> &cur, vector<vector<int>> &res) {
    if (sum >= target) {
        if (sum == target)
            res.emplace_back(cur);
        return;
    }
    for (int i = idx; i < candidates.size(); i++) {
        cur.emplace_back(candidates[i]);
        combinationDFS(candidates, target, i, sum + candidates[i], cur, res);
        cur.pop_back();
    }
}
// 39 https://leetcode.cn/problems/combination-sum/
// O(n*2^n) O(target)
vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<int> cur;
    vector<vector<int>> res;
    combinationDFS(candidates, target, 0, 0, cur, res);
    return res;
}

bool vaildIp(string &str) {
    if (str.size() < 1 || str.size() > 3)
        return false;
    if (str.size() > 1 && str[0] == '0')
        return false;
    int num = 0;
    for (char &ch : str) {
        num = num * 10 + (ch - '0');
    }
    return num <= 255;
}

void ipDfs(const string &s, int idx, vector<string> &ipv4, vector<string> &res) {
    if (ipv4.size() > 4)
        return;
    if (idx == s.size() && ipv4.size() == 4) {
        string tmp = ipv4[0];
        for (int i = 1; i < 4; i++) {
            tmp += ("." + ipv4[i]);
        }
        res.emplace_back(tmp);
        return;
    }
    for (int i = idx; i < s.size(); i++) {
        string tmp = s.substr(idx, i - idx + 1);
        if (vaildIp(tmp)) {
            ipv4.emplace_back(tmp);
            ipDfs(s, i + 1, ipv4, res);
            ipv4.pop_back();
        }
    }
}

// 93 https://leetcode.cn/problems/restore-ip-addresses/
vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    vector<string> ipv4;
    ipDfs(s, 0, ipv4, res);
    return res;
}
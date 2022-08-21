#include <queue>
#include <vector>
using namespace std;

int dir[5] = {-1, 0, 1, 0, -1};

void dfs(vector<vector<int>> &grid, int m, int n, int x, int y) {
    if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != 1)
        return;
    grid[x][y] = 2;
    for (int k = 0; k < 4; ++k) {
        dfs(grid, m, n, x + dir[k], y + dir[k + 1]);
    }
}

int bfs(vector<vector<int>> &grid, int m, int n) {
    queue<pair<int, int>> qu;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 1) {
                qu.emplace(i, j);
            }
        }
    }
    int step = 0;
    while (!qu.empty()) {
        step++;
        int size = qu.size();
        while (size--) {
            auto p = qu.front();
            qu.pop();
            for (int k = 0; k < 4; ++k) {
                int x = p.first + dir[k];
                int y = p.second + dir[k + 1];
                if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 1)
                    continue;
                if (grid[x][y] == 2)
                    return step - 1;
                grid[x][y] = 1;
                qu.emplace(x, y);
            }
        }
    }
    return 0;
}

// 934 https://leetcode.cn/problems/shortest-bridge/
int shortestBridge(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 1) {
                dfs(grid, m, n, i, j);
                return bfs(grid, m, n);
            }
        }
    }
    return -1;
}

// 1765 https://leetcode.cn/problems/map-of-highest-peak/
vector<vector<int>> highestPeak(vector<vector<int>> &isWater) {
    if (isWater.empty())
        return {};
    queue<pair<int, int>> qu;
    int m = isWater.size(), n = isWater[0].size();
    vector<vector<int>> res(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (isWater[i][j] == 1)
                qu.emplace(i, j);
        }
    }
    int step = 0;
    int dirs[5] = {-1, 0, 1, 0, -1};
    while (!qu.empty()) {
        step++;
        int size = qu.size();
        for (int i = 0; i < size; i++) {
            auto p = qu.front();
            qu.pop();
            for (int j = 0; j < 4; j++) {
                int x = p.first + dirs[j];
                int y = p.second + dirs[j + 1];
                if (x < 0 || x == m || y < 0 || y == n || isWater[x][y] == 1)
                    continue;
                qu.emplace(x, y);
                isWater[x][y] = 1;
                res[x][y] = step;
            }
        }
    }
    return res;
}
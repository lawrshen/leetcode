#include <bits/stdc++.h>
using namespace std;

bool isBipartite(vector<vector<int>> &graph) {
    enum color { WHITE,
                 RED,
                 BLUE };
    int n = graph.size();
    vector<color> visit(n, WHITE);
    queue<int> qu;
    for (int i = 0; i < n; i++) {
        if (visit[i] != WHITE)
            continue;
        qu.emplace(i);
        visit[i] = RED;
        while (!qu.empty()) {
            int size = qu.size();
            int u = qu.front();
            qu.pop();
            for (int &v : graph[u]) {
                if (visit[v] == WHITE) {
                    visit[v] = visit[u] == RED ? BLUE : RED;
                    qu.emplace(v);
                } else if (visit[v] == visit[u]) {
                    return false;
                }
            }
        }
    }

    return true;
}
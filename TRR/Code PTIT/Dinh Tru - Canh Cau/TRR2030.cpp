#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

int n, connected = 0, c = 0;
std::vector<int> visited;
std::vector<std::vector<int>> a;
std::vector<std::pair<int, int>> edges;
std::vector<std::pair<int, int>> result;

void bfs(int u, int s, int t) {
    visited[u] = true;
    std::queue<int> queue;
    queue.push(u);

    while (!queue.empty()) {
        int u = queue.front();
        queue.pop();
        for (int v = 1; v <= n; ++v) {
            if (u == s && v == t || u == t && v == s) continue;
            if (visited[v] || !a[u][v]) continue;
            visited[v] = true;
            queue.push(v);
        }
    }
}

int main() {
    std::ifstream input("TK.INP");
    std::ofstream print("TK.OUT");

    input >> n;

    visited.assign(n + 1, false);
    a.assign(n + 1, std::vector<int>(n + 1));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            input >> a[i][j];
            if (a[i][j] && i < j) {
                edges.push_back({i, j});
            }
        }
    }

    for (int u = 1; u <= n; ++u) {
        if (visited[u]) continue;
        bfs(u, -1, -1);
        ++connected;
    }

    for (const auto &[s, t] : edges) {
        visited.assign(n + 1, false);
        int count = 0;
        for (int u = 1; u <= n; ++u) {
            if (visited[u]) continue;
            bfs(u, s, t);
            ++count;
        }
        if (count > connected) {
            ++c;
            result.push_back({s, t});
        }
    }

    print << c << "\n";
    for (const auto &[u, v] : result) print << u << " " << v << "\n";

    return 0;
}
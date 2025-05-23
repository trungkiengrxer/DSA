#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

int t, n, s;
std::vector<bool> visited;
std::vector<std::vector<int>> a;
std::vector<std::pair<int, int>> tree;

void dfs(int u) {
    visited[u] = true;
    for (int v = 1; v <= n; ++v) {
        if (a[u][v] && !visited[v]) {
            tree.push_back({u, v});
            dfs(v);
        }
    }
}

void bfs(int u) {
    visited[u] = true;
    std::queue<int> queue;
    queue.push(u);

    while (!queue.empty()) {
        u = queue.front();
        queue.pop();
        for (int v = 1; v <= n; ++v) {
            if (a[u][v] && !visited[v]) {
                visited[v] = true;
                queue.push(v);
                tree.push_back({u, v});
            }
        }
    }
}

int main() {
    std::cin >> t >> n >> s;
    visited.assign(n + 1, false);
    a.assign(n + 1, std::vector<int>(n + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) std::cin >> a[i][j];
    }

    if (t == 1)
        dfs(s);
    else
        bfs(s);

    if (tree.size() != n - 1) {
        std::cout << 0;
        return 0;
    }
    
    std::cout << tree.size() << "\n";
    for (const auto &[u, v] : tree) {
        std::cout << u << " " << v << "\n";
    }

    return 0;
}
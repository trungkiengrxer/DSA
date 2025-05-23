#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

int t, n, m, s;
std::vector<bool> visited;
std::vector<std::vector<int>> adj;
std::vector<std::pair<int, int>> tree;

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (visited[v]) continue;
        tree.push_back({u, v});
        dfs(v);
    }
}

void bfs(int u) {
    visited[u] = true;
    std::queue<int> queue;
    queue.push(u);

    while (!queue.empty()) {
        u = queue.front();
        queue.pop();
        for (int v : adj[u]) {
            if (visited[v]) continue;
            visited[v] = true;
            queue.push(v);
            tree.push_back({u, v});
        }
    }
}

int main() {
    std::cin >> t >> n >> m >> s;
    visited.assign(n + 1, false);
    adj.assign(n + 1, std::vector<int>());
    for (int i = 1; i <= m; ++i) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
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
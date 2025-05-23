#include <algorithm>
#include <iostream>
#include <vector>

int n, m;
std::vector<bool> visited;
std::vector<std::vector<int>> adj;

int dfs(int u) {
    visited[u] = true;
    int size = 1;
    for (int v : adj[u]) {
        if (visited[v]) continue;
        size += dfs(v);
    }
    return size;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        std::cin >> n >> m;

        adj.assign(n + 1, std::vector<int>());
        visited.assign(n + 1, false);

        for (int i = 0; i < m; ++i) {
            int u, v;
            std::cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int max_component = 0;

        for (int u = 1; u <= n; ++u) {
            if (visited[u]) continue;
            int size = dfs(u);
            max_component = std::max(max_component, size);
        }

        std::cout << max_component << "\n";
    }
}

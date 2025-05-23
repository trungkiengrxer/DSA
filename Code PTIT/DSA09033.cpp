#include <iostream>
#include <vector>

int n, m;
std::vector<bool> visited;
std::vector<std::vector<int>> adj;

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (visited[v]) continue;
        dfs(v);
    }
}

bool is_connected() {
    for (int u = 1; u <= n; ++u) {
        if (!visited[u]) return false;
    }
    return true;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        std::cin >> n >> m;

        visited.assign(n + 1, false);
        adj.assign(n + 1, std::vector<int>());

        for (int i = 1; i <= m; ++i) {
            int u, v;
            std::cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(1);

        if (is_connected())
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }
}
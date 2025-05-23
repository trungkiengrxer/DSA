#include <algorithm>
#include <iostream>
#include <stack>
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

        int connected = 0;
        for (int u = 1; u <= n; ++u) {
            if (visited[u]) continue;
            dfs(u);
            ++connected;
        }

        for (int u = 1; u <= n; ++u) {
            int count = 0;
            visited.assign(n + 1, false);
            visited[u] = true;

            for (int v = 1; v <= n; ++v) {
                if (visited[v]) continue;
                dfs(v);
                ++count;
            }

            if (count > connected) std::cout << u << " ";
        }

        std::cout << "\n";
    }
}
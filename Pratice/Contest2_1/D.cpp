#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

bool found;
int n, m, x, y, count;
std::vector<int> visited;
std::vector<std::vector<int>> adj;
std::unordered_set<int> set;

void dfs(int u) {
    if (found) return;
    if (u == y) {
        found = true;
        return;
    }

    visited[u] = true;

    for (int v : adj[u]) {
        if (visited[v]) continue;
        dfs(v);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int t;
    std::cin >> t;

    while (t--) {
        std::cin >> n >> m >> x >> y;

        count = 0;
        found = false;
        visited.assign(n + 1, false);
        adj.assign(n + 1, std::vector<int>());

        for (int i = 1; i <= m; ++i) {
            int u, v;
            std::cin >> u >> v;
            adj[u].push_back(v);
        }

        for (int z = 1; z <= n; ++z) {
            if (z == x || z == y) continue;
            found = false;
            visited.assign(n + 1, false);
            visited[z] = true;
            dfs(x);
            if (!found) ++count;
        }

        std::cout << count << "\n";
    }
}
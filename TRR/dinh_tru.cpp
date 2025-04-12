#include <iostream>
#include <vector>

std::vector<std::vector<int>> adj;
std::vector<bool> visited;

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (visited[v]) continue;
        dfs(v);
    }
}

int main() {
    int n, x, connected_components = 0, count = 0;
    std::cin >> n;

    adj.resize(n + 1);
    visited.assign(n + 1, false);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            std::cin >> x;
            if (x) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    for (int u = 1; u <= n; ++u) {
        if (visited[u]) continue;
        dfs(u);
        ++connected_components;
    }

    for (int u = 1; u <= n; ++u) {
        count = 0;
        visited.assign(n + 1, false);
        visited[u] = true;

        for (int v = 1; v <= n; ++v) {
            if (visited[v]) continue;
            dfs(v);
            ++count;
        }

        if (count > connected_components) std::cout << u << " ";
    }
}
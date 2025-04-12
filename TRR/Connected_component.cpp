#include <iostream>
#include <vector>

int n;
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
    std::cin >> n;

    int count = 0;

    adj.resize(n + 1);
    visited.resize(n + 1, false);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int x;
            std::cin >> x;
            if (x) adj[i].push_back(j);
        }
    }

    for (int u = 1; u <= n; ++u) {
        for (int v : adj[u]) {
            if (visited[v]) continue;
            dfs(v);
            ++count;
        }
    }

    std::cout << count;
}
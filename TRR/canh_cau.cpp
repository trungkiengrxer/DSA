#include <iostream>
#include <vector>

std::vector<std::vector<int>> adj;
std::vector<std::pair<int, int>> edges;
std::vector<bool> visited;

void dfs(int u, int s, int t) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (u == s && v == t || u == t && v == s) continue;
        if (visited[v]) continue;
        dfs(v, s, t);
    }
}

int main() {
    int n, x, connected_components = 0, count = 0;
    std::cin >> n;

    edges.clear();
    adj.resize(n + 1);
    visited.assign(n + 1, false);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            std::cin >> x;
            if (x) {
                adj[i].push_back(j);
                adj[j].push_back(i);
                if (i < j) edges.push_back({i, j});
            }
        }
    }

    for (int u = 1; u <= n; ++u) {
        if (visited[u]) continue;
        dfs(u, -1, -1);
        ++connected_components;
    }

    for (const auto edge : edges) {
        int s = edge.first, t = edge.second;
        visited.assign(n + 1, false);
        count = 0;

        for (int u = 1; u <= n; ++u) {
            if (visited[u]) continue;
            dfs(u, s, t);
            ++count;
        }

        if (count > connected_components) std::cout << s << " " << t << "\n";
    }
}
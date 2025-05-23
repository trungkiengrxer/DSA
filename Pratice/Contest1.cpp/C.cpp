#include <iostream>
#include <queue>
#include <vector>

int n, m, s, e;
std::vector<std::vector<int>> adj;
std::vector<int> visited;

int bfs() {
    std::queue<std::pair<int, int>> queue;

    visited[s] = true;
    queue.push({s, 0});

    while (!queue.empty()) {
        auto [u, distance] = queue.front();
        queue.pop();

        for (int v : adj[u]) {
            if (visited[v]) continue;
            visited[v] = true;
            if (v == e) return distance + 1;
            queue.push({v, distance + 1});
        }
    }

    return -1;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        std::cin >> n >> m >> s >> e;

        adj.assign(n + 1, std::vector<int>());
        visited.assign(n + 1, false);

        for (int i = 1; i <= m; ++i) {
            int u, v;
            std::cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        std::cout << bfs() << "\n";
    }
}
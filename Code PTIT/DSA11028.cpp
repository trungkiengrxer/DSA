#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

std::vector<std::vector<int>> adj;
std::vector<int> visited;
std::vector<int> distance;

void bfs(int start) {
    std::queue<int> queue;

    visited[start] = true;
    distance[start] = 0;
    queue.push(start);

    while (!queue.empty()) {
        int u = queue.front();
        queue.pop();

        for (int v : adj[u]) {
            if (visited[v]) continue;
            visited[v] = true;
            distance[v] = distance[u] + 1;
            queue.push(v);
        }
    }
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        visited.assign(n + 1, false);
        distance.assign(n + 1, 0);
        adj.assign(n + 1, std::vector<int>());

        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            std::cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        bfs(1);

        std::cout << *std::max_element(distance.begin(), distance.end()) << "\n";
    }
}
#include <iostream>
#include <queue>
#include <vector>

int n;
std::vector<std::vector<int>> a;
std::vector<std::vector<int>> adj;
std::vector<bool> visited;

void bfs(int u) {
    visited[u] = true;

    std::queue<int> queue;

    queue.push(u);

    while (!queue.empty()) {
        int u = queue.front();
        queue.pop();

        std::cout << u << " ";

        for (int v : adj[u]) {
            if (visited[v]) continue;
            queue.push(v);
            visited[v] = true;
        }
    }
}

int main() {
    std::cin >> n;

    visited.resize(n + 1, false);
    a.resize(n + 1, std::vector<int>(n + 1));
    adj.resize(n + 1);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            std::cin >> a[i][j];
            if (a[i][j]) adj[i].push_back(j);
        }
    }

    bfs(1);
}
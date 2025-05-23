#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

int n, m, s;
bool found;
std::vector<bool> visited;
std::vector<int> parent;
std::vector<std::vector<int>> adj;

void bfs(int e) {
    std::queue<int> queue;

    queue.push(s);
    visited[s] = true;

    while (!queue.empty()) {
        int u = queue.front();
        queue.pop();

        for (int v : adj[u]) {
            if (visited[v]) continue;
            parent[v] = u;
            if (v == e) {
                found = true;
                break;
            }
            visited[v] = true;
            queue.push(v);
        }

        if (found) break;
    }
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        std::cin >> n >> m >> s;

        adj.assign(n + 1, std::vector<int>());

        for (int i = 1; i <= m; ++i) {
            int u, v;
            std::cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int e = 1; e <= n; ++e) {
            std::vector<int> path;
            visited.assign(n + 1, false);
            parent.assign(n + 1, -1);
            found = false;
            if (e == s) continue;
            bfs(e);

            if (!found) {
                std::cout << "No path\n";
                continue;
            }

            for (int v = e; v != -1; v = parent[v]) path.push_back(v);

            std::reverse(path.begin(), path.end());

            for (const int v : path) std::cout << v << " ";
            std::cout << "\n";
        }
    }
}
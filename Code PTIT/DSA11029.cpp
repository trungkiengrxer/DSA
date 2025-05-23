#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

std::vector<int> visited;
std::vector<int> distance;
std::vector<int> path;
std::vector<std::vector<int>> adj;
std::vector<std::vector<int>> result;

bool is_leaf(int u) {
    return adj[u].size() == 1 && u != 1;
}

void dfs(int u) {
    visited[u] = true;
    path.push_back(u);

    for (int v : adj[u]) {
        if (visited[v]) continue;
        dfs(v);
    }

    if (is_leaf(u)) result.push_back(path);
    path.pop_back();
}

bool comparator(std::vector<int> &a, std::vector<int> &b) {
    return a.back() < b.back();
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        path.clear();
        result.clear();
        visited.assign(n + 1, false);
        distance.assign(n + 1, 0);
        adj.assign(n + 1, std::vector<int>());

        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            std::cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(1);

        std::sort(result.begin(), result.end(), comparator);

        for (const auto &path : result) {
            for (const auto &u : path) std::cout << u << " ";
            std::cout << "\n";
        }
    }
}
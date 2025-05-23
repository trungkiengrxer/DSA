#include <iostream>
#include <vector>

bool done;
int distance = 0;
std::vector<int> visited;
std::vector<std::vector<int>> adj;

void dfs(int u, int t, int count) {
    if (done) return;
    visited[u] = true;

    if (u == t) {
        distance = count;
        done = true;
        return;
    }

    for (int v : adj[u]) {
        if (visited[v]) continue;
        dfs(v, t, count + 1);
    }
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        adj.assign(n + 1, std::vector<int>());

        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            std::cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int q;
        std::cin >> q;

        while (q--) {
            int u, v;
            std::cin >> u >> v;

            done = false;
            distance = 0;
            visited.assign(n + 1, false);

            dfs(u, v, 0);

            std::cout << distance << "\n";
        }
    }
}
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

int n, m;
std::set<std::pair<int, int>> edges;
std::vector<bool> visited;
std::vector<std::vector<int>> adj;

void dfs(int u, std::vector<int>& comp) {
    visited[u] = true;
    comp.push_back(u);
    for (int v : adj[u]) {
        if (!visited[v]) dfs(v, comp);
    }
}

bool is_connected(int u, int v) { return edges.count({u, v}) || edges.count({v, u}); }

int main() {
    std::cin >> n >> m;
    adj.assign(n + 1, {});
    visited.assign(n + 1, false);
    edges.clear();

    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.insert({u, v});
    }

    std::vector<int> comp1;
    dfs(1, comp1);

    std::vector<bool> in_comp1(n + 1, false);
    for (int u : comp1) in_comp1[u] = true;

    int best = comp1.size();
    visited.assign(n + 1, false);
    for (int u : comp1) visited[u] = true;

    for (int i = 1; i <= n; ++i) {
        if (visited[i]) continue;

        std::vector<int> comp2;
        dfs(i, comp2);

        bool can_connect = false;
        for (int u : comp1) {
            for (int v : comp2) {
                if (!is_connected(u, v)) {
                    can_connect = true;
                    break;
                }
            }
            if (can_connect) break;
        }

        if (can_connect) {
            best = std::max(best, (int)(comp1.size() + comp2.size()));
        }
    }

    std::cout << best << "\n";
}

#include <iostream>
#include <stack>
#include <vector>

std::stack<int> stack;
std::vector<bool> visited;
std::vector<std::vector<int>> adj;
std::vector<std::vector<int>> reversed_adj;

void dfs(int u) {
    visited[u] = true;
    stack.push(u);
    for (int v : adj[u]) {
        if (visited[v]) continue;
        dfs(v);
    }
}

void reversed_dfs(int u) {
    visited[u] = true;
    for (int v : reversed_adj[u]) {
        if (visited[v]) continue;
        reversed_dfs(v);
    }
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, m, count = 0;
        std::cin >> n >> m;

        while (!stack.empty()) stack.pop();
        visited.assign(n + 1, false);
        adj.assign(n + 1, std::vector<int>());
        reversed_adj.assign(n + 1, std::vector<int>());

        for (int i = 1; i <= m; ++i) {
            int u, v;
            std::cin >> u >> v;
            adj[u].push_back(v);
            reversed_adj[v].push_back(u);
        }

        dfs(1);

        visited.assign(n + 1, false);
        while (!stack.empty()) {
            int u = stack.top();
            stack.pop();
            if (visited[u]) continue;
            reversed_dfs(u);
            ++count;
        }

        if (count == 1)
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }
}
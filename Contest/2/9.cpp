#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

int n, m;
std::stack<int> stack;
std::vector<bool> visited;
std::vector<std::vector<int>> adj;
std::vector<std::vector<int>> reversed_adj;

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (visited[v]) continue;
        dfs(v);
    }
    stack.push(u);
}

void reversed_dfs(int u) {
    visited[u] = true;
    for (int v : reversed_adj[u]) {
        if (visited[v]) continue;
        reversed_dfs(v);
    }
}

int main() {
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

    for (int u = 1; u <= n; ++u) {
        if (visited[u]) continue;
        dfs(u);
    }

    visited.assign(n + 1, false);
    int count = 0;

    while (!stack.empty()) {
        int u = stack.top();
        stack.pop();

        if (visited[u]) continue;
        reversed_dfs(u);
        ++count;
    }

    std::cout << count << "\n";
}
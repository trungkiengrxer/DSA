#include <iostream>
#include <stack>
#include <vector>

std::vector<bool> visited;
std::vector<std::vector<int>> adj;
std::vector<std::vector<int>> reverse_adj;
std::stack<int> stack;

void dfs(int u) {
    visited[u] = true;

    for (int v : adj[u]) {
        if (visited[v]) continue;
        dfs(v);
    }

    stack.push(u);
}

void dfs_with_reverse_graph(int u) {
    visited[u] = true;

    for (int v : reverse_adj[u]) {
        if (visited[v]) continue;
        dfs_with_reverse_graph(v);
    }
}

int main() {
    int n, x, count = 0;
    std::cin >> n;

    visited.assign(n + 1, false);
    adj.resize(n + 1);
    reverse_adj.resize(n + 1);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            std::cin >> x;
            if (x) {
                adj[i].push_back(j);
                reverse_adj[j].push_back(i);
            }
        }
    }

    for (int u = 1; u <= n; ++u) {
        if (visited[u]) continue;
        dfs(u);
    }

    visited.assign(n + 1, false);

    while (!stack.empty()) {
        int u = stack.top();
        stack.pop();

        if (visited[u]) continue;
        dfs_with_reverse_graph(u);
        ++count;
    }

    if (count == 1)
        std::cout << "strongly connected";
    else
        std::cout << "not strongly connected";
}
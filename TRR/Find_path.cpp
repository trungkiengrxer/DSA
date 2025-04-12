#include <iostream>
#include <queue>
#include <vector>

int n, s, t;
bool found = true;
std::vector<std::vector<int>> adj;
std::vector<bool> visited;
std::vector<int> parent;
std::vector<int> trace;

void dfs(int u) {
    visited[u] = true;
    if (u == t) return;

    for (int v : adj[u]) {
        if (visited[v]) continue;
        dfs(v);
        parent[v] = u;
    }
}

void bfs(int u) {
    visited[u] = true;

    std::queue<int> queue;
    queue.push(u);

    while (!queue.empty()) {
        int node = queue.front();

        if (node == t) return;

        queue.pop();

        for (int v : adj[node]) {
            if (visited[v]) continue;
            visited[v] = true;
            parent[v] = node;
            queue.push(v);
        }
    }
}

void find_dfs_path() {
    if (parent[t] == 0) {
        std::cout << "no path";
        found = false;
        return;
    }

    std::cout << "DFS path: ";

    int node = t;
    while (node != s) {
        std::cout << node << " ";
        node = parent[node];
    }
    std::cout << s;
}

void find_bfs_path() {
    if (parent[t] == 0) {
        std::cout << "no path";
        found = false;
        return;
    }

    std::cout << "BFS path: ";

    int node = t;
    while (node != s) {
        std::cout << node << " ";
        node = parent[node];
    }
    std::cout << s;
}

int main() {
    std::cin >> n >> s >> t;

    adj.resize(n + 1);
    parent.resize(n + 1, 0);
    visited.resize(n + 1, false);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int x;
            std::cin >> x;
            if (x) adj[i].push_back(j);
        }
    }

    dfs(s);
    find_dfs_path();

    if (!found) return 0;

    std::cout << "\n";
    parent.assign(n + 1, 0);
    visited.assign(n + 1, false);

    bfs(s);
    find_bfs_path();
}
#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

bool found = false;
int n, u, v, t;
std::vector<std::vector<int>> a;
std::vector<bool> visited;
std::vector<int> parent;

void bfs(int u) {
    parent.assign(n + 1, -1);
    visited[u] = true;

    std::queue<int> queue;
    queue.push(u);

    while (!queue.empty()) {
        int s = queue.front();
        queue.pop();

        if (s == v) return;

        for (int i = 1; i <= n; ++i) {
            if (a[s][i] && !visited[i]) {
                queue.push(i);
                visited[i] = true;
                parent[i] = s;
            }
        }
    }
}

int main() {
    std::ifstream input("TK.INP");
    std::ofstream print("TK.OUT");

    input >> t >> n >> u >> v;

    a.assign(n + 1, std::vector<int>(n + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) input >> a[i][j];
    }

    if (t == 1) {
        int count = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[u][i] && a[i][v]) ++count;
        }
        print << count;
    } else if (t == 2) {
        visited.assign(n + 1, false);

        bfs(u);
        if (parent[v] == -1)
            print << 0;
        else {
            std::vector<int> path;
            for (int s = v; s != -1; s = parent[s]) path.push_back(s);
            std::reverse(path.begin(), path.end());
            for (int x : path) print << x << " ";
        }
    }

    return 0;
}
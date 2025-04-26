#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

int n, connected = 0, t = 0;
std::vector<bool> visited;
std::vector<int> result;
std::vector<std::vector<int>> a;

void bfs(int u) {
    visited[u] = true;
    std::queue<int> queue;
    queue.push(u);

    while (!queue.empty()) {
        int u = queue.front();
        queue.pop();
        for (int v = 1; v <= n; ++v) {
            if (!visited[v] && a[u][v]) {
                visited[v] = true;
                queue.push(v);
            }
        }
    }
}

int main() {
    std::ifstream input("TK.INP");
    std::ofstream print("TK.OUT");

    input >> n;

    a.assign(n + 1, std::vector<int>(n + 1));
    visited.assign(n + 1, false);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) input >> a[i][j];
    }

    for (int u = 1; u <= n; ++u) {
        if (visited[u]) continue;
        bfs(u);
        ++connected;
    }

    for (int u = 1; u <= n; ++u) {
        int count = 0;
        visited.assign(n + 1, false);
        visited[u] = true;
        for (int v = 1; v <= n; ++v) {
            if (visited[v]) continue;
            bfs(v);
            ++count;
        }
        if (count > connected) {
            ++t;
            result.push_back(u);
        }
    }

    print << t << "\n";
    for (const int &u : result) print << u << " ";

    return 0;
}
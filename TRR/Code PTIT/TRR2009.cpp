#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

int n;
std::vector<bool> visited;
std::vector<int> path;
std::vector<std::vector<int>> combination;
std::vector<std::vector<int>> a;

void dfs(int u) {
    visited[u] = true;
    path.push_back(u);

    for (int i = 1; i <= n; ++i) {
        if (!visited[i] && a[u][i]) {
            dfs(i);
        }
    }
}

int main() {
    std::ifstream input("TK.INP");
    std::ofstream print("TK.OUT");

    input >> n;

    visited.assign(n + 1, false);
    a.assign(n + 1, std::vector<int>(n + 1));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) input >> a[i][j];
    }

    for (int u = 1; u <= n; ++u) {
        if (!visited[u]) {
            path.clear();
            dfs(u);
            std::sort(path.begin(), path.end());
            combination.push_back(path);
        }
    }

    print << combination.size() << "\n";
    for (const auto &result : combination) {
        for (const auto &num : result) print << num << " ";
        print << "\n";
    }
}
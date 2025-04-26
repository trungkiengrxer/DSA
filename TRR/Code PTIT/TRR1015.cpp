#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

int main() {
    std::ifstream input("DT.INP");
    std::ofstream print("DT.OUT");

    int t, n, m;

    input >> t >> n >> m;

    std::vector<std::pair<int, int>> edges;

    for (int i = 1; i <= m; ++i) {
        int u, v;
        input >> u >> v;
        edges.push_back({u, v});
    }

    if (t == 1) {
        std::vector<int> deg_out(n + 1, 0);
        std::vector<int> deg_in(n + 1, 0);

        for (const auto &[u, v] : edges) {
            ++deg_out[u];
            ++deg_in[v];
        }

        for (int i = 1; i <= n; ++i) print << deg_in[i] << " " << deg_out[i] << "\n";
    } else {
        print << n << "\n";
        std::vector<std::vector<int>> a(n + 1, std::vector<int>(n + 1, 0));

        for (const auto &[u, v] : edges) a[u][v] = 1;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) print << a[i][j] << " ";
            print << "\n";
        }
    }
}
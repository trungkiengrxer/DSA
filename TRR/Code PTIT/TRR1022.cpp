#include <algorithm>
#include <fstream>
#include <iostream>
#include <tuple>
#include <vector>

int main() {
    std::ifstream input("DT.INP");
    std::ofstream print("DT.OUT");

    int t, n, m;
    input >> t >> n >> m;

    std::vector<std::tuple<int, int, int>> edges;

    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        input >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    if (t == 1) {
        std::vector<int> deg_in(n + 1, 0);
        std::vector<int> deg_out(n + 1, 0);

        for (const auto &[u, v, w] : edges) {
            ++deg_out[u];
            ++deg_in[v];
        }

        for (int i = 1; i <= n; ++i) print << deg_in[i] << " " << deg_out[i] << "\n";
    } else if (t == 2) {
        std::vector<std::vector<int>> a(n + 1, std::vector<int>(n + 1, 10000));

        for (int i = 1; i <= n; ++i) a[i][i] = 0;
        for (const auto &[u, v, w] : edges) a[u][v] = w;

        print << n << "\n";
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) print << a[i][j] << " ";
            print << "\n";
        }
    }

    return 0;
}
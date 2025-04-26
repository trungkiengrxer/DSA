#include <fstream>
#include <iostream>
#include <vector>

int main() {
    std::ifstream input("DT.INP");
    std::ofstream print("DT.OUT");

    int t, n;
    input >> t >> n;

    std::vector<std::vector<int>> a(n + 1, std::vector<int>(n + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) input >> a[i][j];
    }

    if (t == 1) {
        std::vector<int> deg_out(n + 1, 0);
        std::vector<int> deg_in(n + 1, 0);

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                deg_out[i] += a[i][j];
                deg_in[i] += a[j][i];
            }
        }

        for (int i = 1; i <= n; ++i) print << deg_in[i] << " " << deg_out[i] << "\n";
    } else {
        std::vector<std::pair<int, int>> edges;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (a[i][j]) edges.push_back({i, j});            }
        }

        print << n << " " << edges.size() << "\n";

        for (const auto &[u, v] : edges) print << u << " " << v << "\n";
    }
}
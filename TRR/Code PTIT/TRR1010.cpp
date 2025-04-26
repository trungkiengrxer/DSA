#include <iostream>
#include <vector>
#include <fstream>
#include <tuple>
#include <unordered_map>

int main() {
    std::ifstream input("DT.INP");
    std::ofstream print("DT.OUT");

    int t, n, w;

    input >> t >> n;

    std::vector<std::tuple<int, int, int>> edges;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            input >> w;

            if (w > 0 && w <= 50) {
                if (i < j) edges.push_back({i, j, w});
            }
        }
    }

    if (t == 1) {
        std::unordered_map<int, int> map;

        for (const auto &[u, v, w] : edges) {
            ++map[u];
            ++map[v];
        }

        for (int i = 1; i <= n; ++i) print << map[i] << " ";
    } else {
        print << n << " " << edges.size() << "\n";
        for (const auto &[u, v, w] : edges) print << u << " " << v << " " << w << "\n";
    }
}
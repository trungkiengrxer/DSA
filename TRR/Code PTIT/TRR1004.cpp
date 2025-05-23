#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
    std::ifstream input("DT.INP");
    std::ofstream print("DT.OUT");

    int t, n, m;
    std::vector<std::pair<int, int>> edges;
    std::unordered_map<int, int> map;

    input >> t >> n >> m;

    for (int i = 1; i <= m; ++i) {
        int x, y;
        input >> x >> y;
        edges.push_back({x, y});
    }

    if (t == 1) {
        for (const auto &[v1, v2] : edges) {
            ++map[v1];
            ++map[v2];
        }

        for (int i = 1; i <= n; ++i) print << map[i] << " ";
    } else {
        print << n << "\n";
        
        std::vector<std::vector<int>> a(n + 1, std::vector<int>(n + 1, 0));

        for (const auto &[v1, v2] : edges) {
            a[v1][v2] = 1;
            a[v2][v1] = 1;
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) print << a[i][j] << " ";
            print << "\n";
        }
    }
}
#include <iostream>
#include <vector>
#include <fstream>

int main() {
    std::ifstream input("DT.INP");
    std::ofstream print("DT.OUT");

    int t, n;
    input >> t >> n;

    std::vector<std::vector<int>> adj(n + 1);

    for (int i = 1; i <= n; ++i) {
        int x;
        input >> x;

        for (int j = 1; j <= x; ++j) {
            int k;
            input >> k;

            adj[i].push_back(k);
        }
    }

    if (t == 1) {
        for (int i = 1; i <= n; ++i) print << adj[i].size() << " ";
    } else {
        

        std::vector<std::pair<int, int>> edges;

        for (int i = 1; i <= n; ++i) {
            for (int j : adj[i]) {
                if (i < j) edges.push_back({i, j});
            }
        }

        print << n << " " << edges.size() << "\n";

        for (const auto &[u, v] : edges) print << u << " " << v << "\n";
    }
}
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
        std::vector<int> deg_out(n + 1);
        std::vector<int> deg_in(n + 1);

        for (const auto &[u, v] : edges) {
            ++deg_out[u];
            ++deg_in[v];
        }

        for (int i = 1; i <= n; ++i) print << deg_in[i] << " " << deg_out[i] << "\n";
    } else if (t == 2) {
        print << n << "\n";
        
        std::vector<std::vector<int>> adj(n + 1);

        for (const auto &[u, v] : edges) adj[u].push_back(v);

        for (int i = 1; i <= n; ++i) {
            print << adj[i].size() << " ";
            for (int j : adj[i]) print << j << " ";
            print << "\n";
        }
    }

    return 0;
}
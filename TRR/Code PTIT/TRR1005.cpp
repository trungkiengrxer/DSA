#include <iostream>
#include <vector>
#include <fstream>

int main() {
    std::ifstream input("DT.INP");
    std::ofstream print("DT.OUT");

    int t, n, m;

    input >> t >> n >> m;

    std::vector<std::vector<int>> adj(n + 1);

    for (int i = 1; i <= m; ++i) {
        int u, v;
        input >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (t == 1) {
        for (int i = 1; i <= n; ++i) print << adj[i].size() << " ";
    } else {
        print << n << "\n";
        for (int i = 1; i <= n; ++i) {
            print << adj[i].size() << " ";
            for (int j : adj[i]) print << j << " ";
            print << "\n";
        }
    }
}
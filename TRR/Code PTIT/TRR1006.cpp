#include <fstream>
#include <iostream>
#include <vector>

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
        print << n << " " << m << "\n";

        int count = 0;
        std::vector<std::vector<int>> incidence(n + 1, std::vector<int>(m, 0));

        for (int i = 1; i <= n; ++i) {
            for (int j : adj[i]) {
                if (i < j) {
                    incidence[i][count] = 1;
                    incidence[j][count] = 1;
                    ++count;
                }
            }
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < m; ++j) print << incidence[i][j] << " ";
            print << "\n";
        }
    }
}
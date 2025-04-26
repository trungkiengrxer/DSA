#include <fstream>
#include <iostream>
#include <vector>

int main() {
    std::ifstream in("DT.INP");
    std::ofstream out("DT.OUT");

    int t, n, x, m = 0;

    in >> t >> n;

    std::vector<std::vector<int>> adj(n + 1);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            in >> x;
            if (x && i < j) {
                ++m;
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    if (t == 1) {
        for (int i = 1; i <= n; ++i) out << adj[i].size() << " ";
    } else {
        out << n << " " << m << "\n";

        std::vector<std::vector<int>> incidence(n + 1, std::vector<int>(m, 0));

        int count = 0;

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
            for (int j = 0; j < m; ++j) out << incidence[i][j] << " ";
            out << "\n";
        }
    }
}
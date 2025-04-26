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
            if (x && j > i) {
                ++m;
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    if (t == 1) {
        for (int i = 1; i <= n; ++i) out << adj[i].size() << " ";
    }

    if (t == 2) {
        out << n << " " << m << "\n";

        for (int i = 1; i <= n; ++i) {
            for (int j : adj[i]) {
                if (i < j) out << i << " " << j << "\n";
            }
        }
    }
}
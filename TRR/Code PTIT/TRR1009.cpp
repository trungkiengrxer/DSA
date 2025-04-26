#include <fstream>
#include <iostream>
#include <vector>

int main() {
    // std::ifstream std::cin("DT.INP");
    // std::ofstream std::cout("DT.OUT");

    int t, n;

    std::cin >> t >> n;
    std::vector<std::vector<int>> adj(n + 1);

    for (int i = 1; i <= n; ++i) {
        int x;
        std::cin >> x;

        for (int j = 1; j <= x; ++j) {
            int k;
            std::cin >> k;
            adj[i].push_back(k);
        }
    }

    if (t == 1) {
        for (int i = 1; i <= n; ++i) std::cout << adj[i].size() << " ";
    } else {
        int count = 0;
        std::vector<std::vector<int>> incidence(n + 1, std::vector<int>(200, 0));

        for (int i = 1; i <= n; ++i) {
            for (int j : adj[i]) {
                if (i < j) {
                    incidence[i][count] = 1;
                    incidence[j][count] = 1;
                    ++count;
                }
            }
        }

        std::cout << n << " " << count << "\n";

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < count; ++j) std::cout << incidence[i][j] << " ";
            std::cout << "\n";
        }
    }
}
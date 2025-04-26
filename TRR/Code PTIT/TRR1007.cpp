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
        print << n << "\n";

        std::vector<std::vector<int>> a(n + 1, std::vector<int>(n + 1, 0));

        for (int i = 1; i <= n; ++i) {
            for (int j : adj[i]) a[i][j] = 1;
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) print << a[i][j] << " ";
            print << "\n";
        }
    }
}
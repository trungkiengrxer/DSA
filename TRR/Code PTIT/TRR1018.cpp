#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

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
        std::vector<int> deg_out(n + 1);
        std::vector<int> deg_in(n + 1);

        for (int i = 1; i <= n; ++i) {
            deg_out[i] += adj[i].size();
            for (int j : adj[i]) {
                ++deg_in[j];
            }
        }

        for (int i = 1; i <= n; ++i) print << deg_in[i] << " " << deg_out[i] << "\n";
    } else if (t == 2) {
        std::vector<std::vector<int>> a(n + 1, std::vector<int>(n + 1, 0));

        for (int i = 1; i <= n; ++i) {
            for (int j : adj[i]) a[i][j] = 1;
        }

        print << n << "\n";
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) print << a[i][j] << " ";
            print << "\n";
        }
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <fstream>
#include <tuple>
#include <unordered_map>

int main() {
    std::ifstream input("DT.INP");
    std::ofstream print("DT.OUT");

    int t, n, m;

    input >> t >> n >> m;

    std::vector<std::vector<int>> a(n + 1, std::vector<int>(n + 1, 10000));

    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        input >> u >> v >> w;
        a[u][v] = w;
        a[v][u] = w;
    }

    for (int i = 1; i <= n; ++i) a[i][i] = 0;
    

    if (t == 1) {
        std::vector<int> deg(n + 1);

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (a[i][j] > 0 && a[i][j] <= 50 && i < j) {
                    ++deg[i];
                    ++deg[j];
                } 
            }
        }

        for (int i = 1; i <= n; ++i) print << deg[i] << " ";

    } else {
        print << n << "\n";
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) print << a[i][j] << " ";
            print << "\n";
        }
    }
}
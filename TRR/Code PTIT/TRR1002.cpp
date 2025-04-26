#include <iostream>
#include <vector>
#include <fstream>

int main() {
    std::ifstream in("DT.INP");
    std::ofstream out("DT.OUT");

    int t, n, x;
    
    in >> t >> n;

    std::vector<std::vector<int>> adj(n + 1);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            in >> x;
            if (x && i < j) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    if (t == 1) {
        for (int i = 1; i <= n; ++i) out << adj[i].size() << " ";
    } else {
        out << n << "\n";

        for (int i = 1; i <= n; ++i) {
            out << adj[i].size() << " ";
            for (int j : adj[i]) out << j << " ";
            out << "\n";
        }
    }
}
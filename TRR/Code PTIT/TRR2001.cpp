#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

bool found = false;
int n, u, v, t;
std::vector<std::vector<int>> a;
std::vector<bool> visited;
std::vector<int> path;

void dfs(int s) {
    if (found) return;
    visited[s] = true;
    path.push_back(s);

    if (s == v) {
        found = true;
        return;
    }

    for (int i = 1; i <= n; ++i) {
        if (a[s][i] && !visited[i]) {
            dfs(i);
            if (found) return;
        }
    }
    
    path.pop_back();
}

int main() {
    std::ifstream input("TK.INP");
    std::ofstream print("TK.OUT");


    input >> t >> n >> u >> v;

    a.assign(n + 1, std::vector<int>(n + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) input >> a[i][j];
    }


    if (t == 1) {
        int count = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[u][i] && a[i][v]) ++count;
        }
        print << count << "\n";
    } else if (t == 2) {
        visited.assign(n + 1, false);
        dfs(u);
        if (!found) print << 0;
        else {
            for (int x : path) print << x << " ";
        }
    }

    return 0;
}
#include <iostream>
#include <vector>

int x[4] = {0, 0, -1, 1};
int y[4] = {-1, 1, 0, 0};

bool is_valid(int i, int j, int n, int m) { return i >= 0 && i < n && j >= 0 && j < m; }

void dfs(int i, int j, int n, int m, std::vector<std::vector<char>> &a, std::vector<std::vector<bool>> &visited) {
    visited[i][j] = true;

    for (int k = 0; k < 4; ++k) {
        int new_i = i + x[k];
        int new_j = j + y[k];
        if (is_valid(new_i, new_j, n, m) && !visited[new_i][new_j] && a[i][j] == '#') {
            dfs(new_i, new_j, n, m, a, visited);
        }
    }
}

int main() {
    int n, m, result = 0;
    std::cin >> n >> m;

    std::vector<std::vector<char>> a(n, std::vector<char>(m));
    std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) std::cin >> a[i][j];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!visited[i][j] && a[i][j] == '#') {
                dfs(i, j, n, m, a, visited);
                ++result;
            }
        }
    }

    std::cout << result;
}
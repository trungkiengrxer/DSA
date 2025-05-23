/*
Cho một bản đồ kích thước N x M được mô tả bằng ma trận A[][].A[i][j] = 1 có nghĩa vị trí (i, j) là nổi trên biển. 2 vị trí (i, j) và (x, y) được coi là liền nhau nếu như nó có chung đỉnh hoặc chung cạnh. Một hòn đảo là một tập hợp các điểm (i, j) mà A[i][j] = 1 và có thể di chuyển giữa hai điểm bất kì trong đó.

Nhiệm vụ của bạn là hãy đếm số lượng đảo xuất hiện trên bản đồ.

Input: Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

Mỗi test bắt đầu bởi 2 số nguyên N và M (1 ≤ N, M ≤ 500).

N dòng tiếp theo, mỗi dòng gồm M số nguyên A[i][j].

Output:  Với mỗi test, in ra số lượng hòn đảo tìm được.
*/

#include <iostream>
#include <vector>
#include <tuple>

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int n, m, count;
std::vector<std::vector<int>> a;

bool is_valid(int i, int j) { return i >= 0 && j >= 0 && i < n && j < m && a[i][j]; }

void dfs(int i, int j) {
    a[i][j] = 0;
    for (int k = 0; k < 8; ++k) {
        int new_i = i + dx[k];
        int new_j = j + dy[k];

        if (is_valid(new_i, new_j)) dfs(new_i, new_j);
    }
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        std::cin >> n >> m;

        count = 0;
        a.assign(n + 1, std::vector<int>(m));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) std::cin >> a[i][j];
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!a[i][j]) continue;
                dfs(i, j);
                ++count;
            }
        }

        std::cout << count << "\n";
    }
}
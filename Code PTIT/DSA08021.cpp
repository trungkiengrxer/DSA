/*
Cho ma trận A[M][N]. Nhiệm vụ của bạn hãy tìm số bước đi ít nhất dịch chuyển từ vị trí A[1][1] đến vị trí A[M][N]. Biết mỗi bước đi ta chỉ được phép dịch chuyển đến vị trí A[i][j+A[i][j]] hoặc vị trí A[i+A[i][j]][j] bên trong ma trận.

Input:
Dòng đầu tiên đưa vào số lượng test T.
Dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất là hai số M, N; phần thứ hai là các phần tử của ma trận A[][]; các số được viết cách nhau một vài khoảng trống.
T, M, N, A[i][j] thỏa mãn ràng buộc: 1≤T≤100; 1≤M, N, A[i][j]≤10^3.

Output:
Đưa ra kết quả mỗi test theo từng dòng. In ra -1 nếu không tìm được đáp án.
*/

#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

bool is_valid(int &x, int &y, int &m, int &n) { return x >= 0 && x < m && y >= 0 && y < n; }

void bfs(int x, int y, int m, int n, bool &found, std::vector<std::vector<int>> &a, std::vector<std::vector<bool>> &visited) {
    std::queue<std::tuple<int, int, int>> queue;
    queue.push({x, y, 0});
    visited[x][y] = true;

    while (!queue.empty()) {
        auto [x, y, steps] = queue.front();
        queue.pop();

        if (x == m - 1 && y == n - 1) {
            std::cout << steps << "\n";
            found = true;
            break;
        }

        int new_x = x + a[x][y];
        int new_y = y + a[x][y];

        if (is_valid(new_x, y, m, n) && !visited[new_x][y]) {
            visited[new_x][y] = true;
            queue.push({new_x, y, steps + 1});
        }

        if (is_valid(x, new_y, m, n) && !visited[x][new_y]) {
            visited[x][new_y] = true;
            queue.push({x, new_y, steps + 1});
        }
    }
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int m, n, steps = 0;
        bool found = false;
        std::cin >> m >> n;

        std::vector<std::vector<int>> a(m, std::vector<int>(n));
        std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) std::cin >> a[i][j];
        }

        bfs(0, 0, m, n, found, a, visited);

        if (!found) std::cout << "-1\n";
    }
}
/*
Cho ma trận A[M][N]. Nhiệm vụ của bạn là đếm tất cả các đường đi từ phần tử A[0][0] đến phần tử A[M-1][N-1]. Bạn chỉ được phép dịch chuyển xuống dưới hoặc sang phải phần tử liền kề với vị trí hiện tại.

Input:
• Dòng đầu tiên đưa vào số lượng bộ test T.
• Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất là hai số M, N tương ứng với số hàng và số cột của ma trận; dòng tiếp theo đưa vào các phần tử của ma trận A[][]; các số được viết cách nhau một vài khoảng trống.
• T, M, N, A[i][j] thỏa mãn ràng buộc: 1≤T ≤10; 1≤M, N, A[i][j]≤100.

Output:
• Đưa ra số cách di chuyển của mỗi test theo từng dòng.
*/

#include <iostream>
#include <vector>

int dx[2] = {1, 0};
int dy[2] = {0, 1};

bool is_valid(int x, int y, int m, int n) {
    return x >= 0 && x < m && y >= 0 && y < n;
}

int dfs(int x, int y, int m, int n) {
    if (x == m - 1 && y == n - 1) return 1;

    int count = 0;

    for (int i = 0; i < 2; ++i) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];

        if (is_valid(new_x, new_y, m, n)) count += dfs(new_x, new_y, m, n);
    }

    return count;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, m;
        std::cin >> m >> n;

        std::vector<std::vector<int>> a(m, std::vector<int>(n));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) std::cin >> a[i][j];
        }

        std::cout << dfs(0, 0, m, n) << "\n";
    }
}
/*
Cho một mê cung bao gồm các khối được biểu diễn như một ma trận nhị phân A[N][N]. Một con chuột đi từ ô đầu tiên góc trái (A[0][0]) đến ô cuối cùng góc phải (A[N-1][N-1]) theo nguyên tắc:

• Down (D): Chuột được phép xuống dưới nếu ô dưới nó có giá trị 1.
• Right (R): Chuột được phép sang phải dưới nếu ô bên phải nó có giá trị 1.
Hãy đưa ra một hành trình của con chuột trên mê cung. Đưa ra -1 nếu chuột không thể đi đến đích.


Input:
• Dòng đầu tiên đưa vào số lượng bộ test T.
• Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất đưa vào số N là kích cỡ của mê cung; dòng tiếp theo đưa vào ma trận nhị phân A[N][N].
• T, N, A[i][j] thỏa mãn ràng buộc: 1≤T ≤10; 2≤N≤10; 0≤A[i][j] ≤1.

Output:
• Đưa ra tất cả đường đi của con chuột trong mê cung theo thứ tự từ điển. Đưa ra -1 nếu chuột không đi được đến đích.
*/

#include <iostream>
#include <string>
#include <vector>

const int dx[2] = {1, 0};
const int dy[2] = {0, 1};

bool is_valid(int i, int j, int n) { return i >= 0 && i < n && j >= 0 && j < n; }

void dfs(int i, int j, int n, std::vector<std::vector<int>> &a, std::vector<std::string> &trace, std::string node) {
    if (i == n - 1 && j == n - 1) {
        trace.push_back(node);
        return;
    }

    a[i][j] = 0;

    for (int k = 0; k < 2; ++k) {
        int new_i = i + dx[k];
        int new_j = j + dy[k];

        if (is_valid(new_i, new_j, n) && a[new_i][new_j] == 1) {
            if (k == 0)
                dfs(new_i, new_j, n, a, trace, node + "D");
            else
                dfs(new_i, new_j, n, a, trace, node + "R");
        }
    }

    a[i][j] = 1;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::string node = "";
        std::vector<std::string> trace;
        std::vector<std::vector<int>> a(n, std::vector<int>(n));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) std::cin >> a[i][j];
        }

        if (a[0][0] == 1) dfs(0, 0, n, a, trace, node);

        if (trace.empty()) {
            std::cout << -1 << "\n";
            continue;
        }

        for (const std::string &result : trace) std::cout << result << " ";
        std::cout << "\n";
    }
}
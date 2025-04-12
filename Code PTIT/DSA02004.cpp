/*
Cho một mê cung bao gồm các khối được biểu diễn như một ma trận nhị phân A[N][N]. Một con chuột đi từ ô đầu tiên góc trái (A[0][0]) đến ô cuối cùng góc phải (A[N-1][N-1]) theo nguyên tắc:
Down (D): Chuột được phép xuống dưới nếu ô dưới nó có giá trị 1.
Right (R): Chuột được phép sang phải dưới nếu ô bên phải nó có giá trị 1.
Left (L): Chuột được phép sang trái dưới nếu ô bên trái nó có giá trị 1.
Up (U): Chuột được phép lên trên nếu ô trên nó có giá trị 1.
Hãy đưa ra tất cả các hành trình của con chuột trên mê cung. Đưa ra -1 nếu chuột không thể đi đến đích.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất đưa vào số N là kích cỡ của mê cung; dòng tiếp theo đưa vào ma trận nhị phân A[N][N].
T, N, A[i][j] thỏa mãn ràng buộc: 1≤T ≤10; 2≤N≤8; 0≤A[i][j] ≤1.

Output:
Đưa ra các xâu ký tự được sắp xếp, trong đó mỗi xâu là một đường đi của con chuột trong mê cung. In ra đáp án theo thứ tự từ điển. Đưa ra -1 nếu chuột không đi được đến đích.
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

bool is_valid(int x, int y, int n) { return x >= 0 && x < n && y >= 0 && y < n; }

void backtrack(int x, int y, int n, std::string trace, std::vector<std::string> &result, std::vector<std::vector<int>> &a) {
    if (x == n - 1 && y == n - 1) {
        result.push_back(trace);
        return;
    }

    a[x][y] = 0;

    for (int i = 0; i < 4; ++i) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];

        if (is_valid(new_x, new_y, n) && a[new_x][new_y] == 1) {
            if (i == 0)
                backtrack(new_x, new_y, n, trace + "D", result, a);
            else if (i == 1)
                backtrack(new_x, new_y, n, trace + "R", result, a);
            else if (i == 2)
                backtrack(new_x, new_y, n, trace + "L", result, a);
            else
                backtrack(new_x, new_y, n, trace + "U", result, a);
        }
    }

    a[x][y] = 1;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<std::vector<int>> a(n, std::vector<int>(n));
        std::string trace = "";
        std::vector<std::string> result;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) std::cin >> a[i][j];
        }

        backtrack(0, 0, n, trace, result, a);

        if (result.empty()) {
            std::cout << "-1\n";
            continue;
        }

        std::sort(result.begin(), result.end());

        for (int i = 0; i < result.size(); ++i) std::cout << result[i] << " ";
        std::cout << "\n";
    }
}
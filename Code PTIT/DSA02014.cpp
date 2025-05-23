/*
Cho tập từ ghi trong trừ điển dic[] và một bảng hai chiều A[M][N] các ký tự. Hãy tạo nên tất cả các từ có mặt trong từ điển dic[] bằng cách nối các ký tự kề nhau trong mảng A[][]. Chú ý, phép nối các ký tự kề nhau trong mảng A[][] được thực hiện theo 8 hướng nhưng không có phần tử A[i][j] nào được lặp lại. Ví dụ với từ điển dic[] ={ “GEEKS”, “FOR”, “QIUZ”, “GO”} và mảng A[][] dưới đây sẽ cho ta kết quả: “GEEKS”, “QUIZ”

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất đưa vào ba số K, M, N tương ứng với số từ của từ điển dic[], số hàng và số cột của ma trận ký tự A[M][N]; dòng tiếp theo đưa vào K từ của từ điển dic[]; dòng cuối cùng đưa vào các phần tử A[i][j].
T, K, M, N thỏa mãn ràng buộc: 1≤T ≤10; 1≤K≤100; 1≤ M, N ≤3.

Output:
Đưa ra theo thứ tự tăng dần các từ có mặt trong từ điển dic[] được tạo ra từ ma trận A[][]. Đưa ra -1 nếu không thể tạo ra từ nào thuộc dic[] từ A[][].
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

int k, m, n;
std::vector<std::vector<char>> a;
std::vector<std::vector<bool>> visited;
std::unordered_set<std::string> prefix, dict;
std::vector<std::string> result;

int dx[8] = {0, 0, -1, 1, -1, 1, -1, 1};
int dy[8] = {-1, 1, 0, 0, -1, -1, 1, 1};

bool is_valid(int i, int j) { return i >= 0 && i < m && j >= 0 && j < n && !visited[i][j]; }

void backtrack(int i, int j, std::string &s) {
    if (!is_valid(i, j)) return;

    char c = a[i][j];
    s.push_back(c);
    visited[i][j] = true;

    if (!prefix.count(s)) {
        s.pop_back();
        visited[i][j] = false;
        return;
    }

    if (dict.count(s)) {
        result.push_back(s);
    }

    for (int k = 0; k < 8; ++k) {
        int new_i = i + dx[k];
        int new_j = j + dy[k];
        backtrack(new_i, new_j, s);
    }

    s.pop_back();
    visited[i][j] = false;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        std::cin >> k >> m >> n;

        dict.clear();
        prefix.clear();
        result.clear();
        a.assign(m, std::vector<char>(n));

        for (int i = 1; i <= k; ++i) {
            std::string s;
            std::cin >> s;

            dict.insert(s);

            for (int len = 1; len <= s.size(); ++len) {
                prefix.insert(s.substr(0, len));
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) std::cin >> a[i][j];
        }

        visited.assign(m, std::vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            std::string temp = "";
            for (int j = 0; j < n; ++j) {
                backtrack(i, j, temp);
            }
        }

        if (result.empty()) {
            std::cout << "-1\n";
            continue;
        }

        for (const std::string &s : result) std::cout << s << " ";
        std::cout << "\n";
    }
}
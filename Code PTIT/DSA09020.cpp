/*
Cho đơn đồ thị vô hướng có n đỉnh dưới dạng danh sách kề.
Hãy biểu diễn đồ thị bằng ma trận kề.

Input: Dòng đầu tiên chứa số nguyên n – số đỉnh của đồ thị (1 ≤  n ≤  1000). n dòng tiếp theo, dòng thứ i chứa các số nguyên là các đỉnh kề với đỉnh i.

Output:  Ma trận kề của đồ thị.
*/

#include <iostream>
#include <sstream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore();

    std::vector<std::vector<int>> a(n, std::vector<int>(n, 0));

    for (int u = 0; u < n; ++u) {
        std::string s;
        std::getline(std::cin, s);

        std::stringstream ss(s);
        int v;

        while (ss >> v) {
            --v;
            a[u][v] = 1;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) std::cout << a[i][j] << " ";
        std::cout << "\n";
    }
}
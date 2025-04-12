/*
Cho đơn đồ thị G vô hướng liên thông được mô tả bởi danh sách kề. Hãy in ra danh sách cạnh tương ứng của G.

Input
Dòng đầu tiên ghi số N là số đỉnh (1<N<50)
N dòng tiếp theo mỗi dòng ghi 1 danh sách kề lần lượt theo thứ tự từ đỉnh 1 đến đỉnh N

Output: Ghi ra lần lượt từng cạnh của đồ thị theo thứ tự tăng dần.
*/

#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore();

    std::vector<std::vector<int>> adj(n + 1);
    std::vector<std::pair<int, int>> edges;

    for (int i = 1; i <= n; ++i) {
        std::string line;
        std::getline(std::cin, line);
        std::stringstream ss(line);
        int j;

        while (ss >> j) adj[i].push_back(j);
    }

    for (int i = 1; i <= n; ++i) {
        for (const int &j : adj[i]) {
            if (i < j) edges.push_back({i, j});
        }
    }

    std::sort(edges.begin(), edges.end());

    for (const auto &[i, j] : edges) {
        std::cout << i << " " << j << "\n";
    }
}
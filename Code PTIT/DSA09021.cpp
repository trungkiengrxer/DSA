/*
Ma trận kề A của một đồ thị vô hướng là một ma trận chỉ có các số 0 hoặc 1 trong đó A[i][j] = 1 có ý nghĩa là đỉnh i kề với đỉnh j (chỉ số tính từ 1).
Danh sách kề thì liệt kê các đỉnh kề với đỉnh đó theo thứ tự tăng dần.
Hãy chuyển biểu diễn đồ thị từ dạng ma trận kề sang dạng danh sách kề.

Input: Dòng đầu tiên chứa số nguyên n – số đỉnh của đồ thị (1 < n ≤ 1000). n dòng tiếp theo, mỗi dòng có n số nguyên có giá trị 0 và 1 mô tả ma trận kề của đồ thị.

Output:  Gồm n dòng, dòng thứ i chứa các số nguyên là đỉnh có nối với đỉnh i và được sắp xếp tăng dần. Dữ liệu đảm bảo mỗi đỉnh có kết nối với ít nhất 1 đỉnh khác.
*/

#include <iostream>
#include <vector>

int main() {
    int n, w;
    std::cin >> n;

    std::vector<std::vector<int>> a(n, std::vector<int>(n));
    std::vector<std::vector<int>> adj(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> w;
            if (w == 1) adj[i].push_back(j);
        }
    }

    for (int u = 0; u < n; ++u) {
        for (int v : adj[u]) std::cout << v + 1 << " ";
        std::cout << "\n";
    }
}
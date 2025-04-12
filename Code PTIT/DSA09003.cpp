/*
Cho đồ thị có hướng G=<V, E> được biểu diễn dưới dạng danh sách cạnh. Hãy viết chương trình thực hiện chuyển đổi biểu diễn đồ thị dưới dạng danh sách kề.

Input:
Dòng đầu tiên đưa vào T là số lượng bộ test.
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm |E| +1 dòng: dòng đầu tiên đưa vào hai số |V|, |E| tương ứng với số đỉnh và số cạnh của đồ thị; |E| dòng tiếp theo đưa vào các bộ đôi uÎV, vÎV tương ứng với một cạnh của đồ thị.
T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤200; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;

Output:
Đưa ra danh sách kề của các đỉnh tương ứng theo khuôn dạng của ví dụ dưới đây. Các đỉnh trong danh sách in ra theo thứ tự tăng dần.
*/

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int v, e;
        std::cin >> v >> e;

        std::vector<std::vector<int>> adj(v + 1);

        while (e--) {
            int i, j;
            std::cin >> i >> j;
            adj[i].push_back(j);
        }

        for (int i = 1; i < adj.size(); ++i) std::sort(adj[i].begin(), adj[i].end());

        for (int i = 1; i < adj.size(); ++i) {
            std::cout << i << ": ";
            for (const int &j : adj[i]) std::cout << j << " ";
            std::cout << "\n";
        }
    }
}
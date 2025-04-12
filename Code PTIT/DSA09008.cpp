/*
Cho đồ thị vô hướng G=<V, E> được biểu diễn dưới dạng danh sách cạnh. Hãy tìm số thành phần liên thông của đồ thị.

Input:
Dòng đầu tiên đưa vào T là số lượng bộ test.
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào hai số |V|, |E| tương ứng với số đỉnh và số cạnh; Dòng tiếp theo đưa vào các bộ đôi uÎV, vÎV tương ứng với một cạnh của đồ thị.
T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤100; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;

Output:
Đưa ra số thành phần liên thông của đồ thị.
*/

#include <iostream>
#include <vector>

void dfs(int u, std::vector<std::vector<int>> &adj, std::vector<bool> &visited) {
    visited[u] = true;

    for (int v : adj[u]) {
        if (visited[v]) continue;
        dfs(v, adj, visited);
    }
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, m, count = 0;
        std::cin >> n >> m;

        std::vector<std::vector<int>> adj(n + 1);
        std::vector<bool> visited(n + 1, false);

        while (m--) {
            int u, v;
            std::cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int u = 1; u <= n; ++u) {
            if (visited[u]) continue;
            dfs(u, adj, visited);
            ++count;
        }

        std::cout << count << "\n";
    }
}
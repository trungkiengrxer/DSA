/*
Cho đồ thị vô hướng G=<V, E> được biểu diễn dưới dạng danh sách cạnh. Hãy tìm số thành phần liên thông của đồ thị bằng thuật toán BFS.

Input:

Dòng đầu tiên đưa vào T là số lượng bộ test.
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào hai số |V|, |E| tương ứng với số đỉnh và số cạnh; Dòng tiếp theo đưa vào các bộ đôi uÎV, vÎV tương ứng với một cạnh của đồ thị.
T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤100; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;
Output:

Đưa ra số thành phần liên thông của đồ thị bằng thuật toán BFS.
*/

#include <iostream>
#include <queue>
#include <vector>

int n, m, count;
std::vector<bool> visited;
std::vector<std::vector<int>> adj;

void bfs(int u) {
    std::queue<int> queue;

    visited[u] = true;
    queue.push(u);

    while (!queue.empty()) {
        u = queue.front();
        queue.pop();

        for (int v : adj[u]) {
            if (visited[v]) continue;
            visited[v] = true;
            queue.push(v);
        }
    }
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        std::cin >> n >> m;

        count = 0;
        visited.assign(1001, false);
        adj.assign(1001, std::vector<int>());

        for (int i = 1; i <= m; ++i) {
            int u, v;
            std::cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int u = 1; u <= n; ++u) {
            if (visited[u]) continue;
            bfs(u);
            ++count;
        }

        std::cout << count << "\n";
    }
}
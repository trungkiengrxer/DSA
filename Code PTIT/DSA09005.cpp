/*
Cho đồ thị vô hướng G=<V, E> được biểu diễn dưới dạng danh sách cạnh. Hãy viết thuật toán duyệt theo chiều rộng bắt đầu tại đỉnh uÎV (BFS(u)=?)

Input:
Dòng đầu tiên đưa vào T là số lượng bộ test.
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào ba số |V|, |E|, uÎV tương ứng với số đỉnh, số cạnh và đỉnh bắt đầu duyệt; Dòng tiếp theo đưa vào các bộ đôi uÎV, vÎV tương ứng với một cạnh của đồ thị.
T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤200; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;

Output:
Đưa ra danh sách các đỉnh được duyệt theo thuật toán BFS(u) của mỗi test theo khuôn dạng của ví dụ dưới đây.
*/

#include <iostream>
#include <queue>
#include <vector>

void bfs(int u, std::vector<int> &trace, std::vector<bool> &visited, std::vector<std::vector<int>> &adj) {
    visited[u] = true;
    trace.push_back(u);

    std::queue<int> queue;
    queue.push(u);

    while (!queue.empty()) {
        int u = queue.front();
        queue.pop();

        for (int v : adj[u]) {
            if (visited[v]) continue;
            queue.push(v);
            visited[v] = true;
            trace.push_back(v);
        }
    }
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int v, e, u;
        std::cin >> v >> e >> u;

        std::vector<std::vector<int>> adj(v + 1);
        std::vector<bool> visited(v + 1, false);
        std::vector<int> trace;

        for (int i = 1; i <= e; ++i) {
            int a, b;
            std::cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        bfs(u, trace, visited, adj);

        for (int i = 0; i < trace.size(); ++i) std::cout << trace[i] << " ";
        std::cout << "\n";
    }
}
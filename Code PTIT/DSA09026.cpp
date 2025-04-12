/*
Cho đồ thị có hướng G=<V, E> được biểu diễn dưới dạng danh sách cạnh. Hãy tìm đường đi từ đỉnh uÎV đến đỉnh vÎV trên đồ thị bằng thuật toán BFS.

Input:
Dòng đầu tiên đưa vào T là số lượng bộ test.
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào bốn số |V|, |E|, sÎV, tÎV tương ứng với số đỉnh, số cạnh,  đỉnh u, đỉnh v; |E| Dòng tiếp theo đưa vào các bộ đôi uÎV, vÎV tương ứng với một cạnh của đồ thị.
T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤100; 1≤|V|≤10^3; 1≤|E|≤|V|(|V|-1)/2;

Output:
Đưa ra đường đi từ đỉnh s đến đỉnh t của mỗi test theo thuật toán BFS của mỗi test theo khuôn dạng của ví dụ dưới đây. Nếu không có đáp án, in ra -1.
*/

#include <iostream>
#include <queue>
#include <vector>

void bfs(int u, int v, std::vector<bool> &visited, std::vector<int> &parent, std::vector<std::vector<int>> &adj) {
    visited[u] = true;

    std::queue<int> queue;

    queue.push(u);

    while (!queue.empty()) {
        int u = queue.front();
        queue.pop();

        if (u == v) break;

        for (int i : adj[u]) {
            if (visited[i]) continue;
            queue.push(i);
            parent[i] = u;
            visited[i] = true;
        }
    }
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, e, u, v;
        std::cin >> n >> e >> u >> v;

        std::vector<std::vector<int>> adj(n + 1);
        std::vector<bool> visited(n + 1, false);
        std::vector<int> parent(n + 1, -1);

        while (e--) {
            int a, b;
            std::cin >> a >> b;
            adj[a].push_back(b);
        }

        bfs(u, v, visited, parent, adj);

        if (!visited[v]) {
            std::cout << "-1\n";
            continue;
        }

        std::vector<int> trace;

        for (int i = v; i != -1; i = parent[i]) trace.push_back(i);

        for (int i = trace.size() - 1; i >= 0; --i) std::cout << trace[i] << " ";
        std::cout << "\n";
    }
}
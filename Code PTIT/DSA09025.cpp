/*
Cho đồ thị có hướng G=<V, E> được biểu diễn dưới dạng danh sách cạnh. Hãy tìm đường đi từ đỉnh sÎV đến đỉnh tÎV trên đồ thị bằng thuật toán DFS.

Input:
Dòng đầu tiên đưa vào T là số lượng bộ test.
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào bốn số |V|, |E|, sÎV, tÎV tương ứng với số đỉnh, số cạnh,  đỉnh u, đỉnh v; Dòng tiếp theo đưa vào các bộ đôi uÎV, vÎV tương ứng với một cạnh của đồ thị.
T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤100; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;

Output:
Đưa ra đường đi từ đỉnh s đến đỉnh t của mỗi test theo thuật toán DFS của mỗi test theo khuôn dạng của ví dụ dưới đây. Nếu không có đáp án, in ra -1.
*/

#include <iostream>
#include <vector>

void dfs(int u, int v, bool &found, std::vector<std::vector<int>> &adj, std::vector<bool> &visited, std::vector<int> &trace) {
    if (u == v) {
        trace.push_back(u);
        found = true;
        return;
    }

    visited[u] = true;
    trace.push_back(u);

    for (int i : adj[u]) {
        if (visited[i]) continue;
        dfs(i, v, found, adj, visited, trace);
        if (found) return;
    }

    trace.pop_back();
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, e, u, v;
        bool found = false;
        std::cin >> n >> e >> u >> v;

        std::vector<std::vector<int>> adj(n + 1);
        std::vector<bool> visited(n + 1);
        std::vector<int> trace;

        while (e--) {
            int a, b;
            std::cin >> a >> b;
            adj[a].push_back(b);
        }

        dfs(u, v, found, adj, visited, trace);

        if (!found) {
            std::cout << "-1\n";
            continue;
        }
        for (int i = 0; i < trace.size(); ++i) std::cout << trace[i] << " ";
        std::cout << "\n";
    }
}
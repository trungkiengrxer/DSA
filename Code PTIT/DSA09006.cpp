/*
Cho đồ thị vô hướng G=<V, E> được biểu diễn dưới dạng danh sách cạnh. Hãy tìm đường đi từ đỉnh sÎV đến đỉnh tÎV trên đồ thị bằng thuật toán DFS.

Input:

Dòng đầu tiên đưa vào T là số lượng bộ test.
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào bốn số |V|, |E|, sÎV, tÎV tương ứng với số đỉnh, số cạnh,  đỉnh u, đỉnh v; Dòng tiếp theo đưa vào các bộ đôi uÎV, vÎV tương ứng với một cạnh của đồ thị.
T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤100; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;
Output:

Đưa ra đường đi từ đỉnh s đến đỉnh t của mỗi test theo thuật toán DFS của mỗi test theo khuôn dạng của ví dụ dưới đây. Nếu không có đáp án, in ra -1.
*/

#include <algorithm>
#include <iostream>
#include <vector>

bool found;
int n, m, s, e;
std::vector<std::vector<int>> adj;
std::vector<bool> visited;
std::vector<int> trace;

void dfs(int u) {
    visited[u] = true;
    trace.push_back(u);  

    if (u == e) {
        found = true;
        return;
    }

    for (int v : adj[u]) {
        if (visited[v]) continue;
        if (found) return;
        dfs(v);
    }

    if (!found) trace.pop_back(); 
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        std::cin >> n >> m >> s >> e;

        trace.clear();
        found = false;
        visited.assign(n + 1, false);
        adj.assign(n + 1, std::vector<int>());

        for (int i = 1; i <= m; ++i) {
            int u, v;
            std::cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 1; i <= n; ++i) {
            std::sort(adj[i].begin(), adj[i].end());
        }

        dfs(s);

        if (!found) {
            std::cout << "-1\n";
            continue;
        }
        for (int u : trace) std::cout << u << " ";
        std::cout << "\n";
    }
}
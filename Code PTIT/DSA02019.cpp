/*
Cho đồ thị vô hướng có N đỉnh và M cạnh. Bạn hãy tìm đường đi dài nhất trên đồ thị, sao cho mỗi cạnh chỉ được đi qua nhiều nhất 1 lần.

Input: Dòng đầu tiên là số lượng bộ test T (T ≤ 10). Mỗi test bắt đầu bằng số nguyên N và M (1 ≤ N, M ≤ 20). Các đỉnh đánh dấu từ 0, 1, …, N-1. M dòng tiếp theo, mỗi dòng gồm 2 số u, v cho biết có cạnh nối giữa uàv.

Output: Với mỗi test, in ra đáp án tìm được, mỗi xâu in ra trên một dòng.
*/

#include <iostream>
#include <vector>

int n, m;
std::vector<bool> visited;
std::vector<std::vector<int>> adj;

void dfs()
int main() {
    int t;
    std::cin >> t;

    while (t--) {
        std::cin >> n >> m; 

        visited.assign(n + 1, false);
        adj.assign(n + 1, std::vector<int>());

        for (int i = 1; i <= m; ++i) {
            int u, v;
            std::cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
}
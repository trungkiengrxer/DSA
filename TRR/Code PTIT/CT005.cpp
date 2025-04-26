/*
(Tệp chương trình: CT.CPP; Thời gian chạy chương trình ≤ 1 giây)

Cho trước đồ thị có hướng G = (V, E) gồm n đỉnh biểu diễn dưới dạng danh sách cạnh và một đỉnh u.

Yêu cầu: Tìm tất cả các chu trình Hamilton của G bắt đầu tại u.

Dữ liệu: Vào từ tệp CT.INP:

Dòng đầu chứa ba số nguyên dương n, m và u, trong đó n là số đỉnh, m là số cạnh và u là một đỉnh của G, với 1 <=u <= n <= 100, m <= n(n-1)/2.
Trong m dòng tiếp theo, mỗi dòng thứ i (1 <= i <=m) chứa hai số nguyên ui,vi là đỉnh đầu và đỉnh cuối của cạnh ei, với 1 <= ui, vi <= n.
Kết quả: Ghi ra tệp CT.OUT:

Dòng đầu ghi giá trị t là số lượng các chu trình Hamilton tìm được.
Trong trường hợp t > 0, tiếp theo ghi ra t dòng, mỗi dòng ghi dãy các đỉnh của một chu trình Hamilton.
*/

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

int n, m, start;
std::vector<std::vector<int>> adj;
std::vector<bool> visited;
std::vector<int> path;
std::vector<std::vector<int>> result;

void hamilton(int u) {
    if (path.size() == n) {
        for (int v : adj[u]) {
            if (v == start) {
                path.push_back(start);
                result.push_back(path);
                path.pop_back();
                break;
            }
        }
        return;
    }

    for (int v : adj[u]) {
        if (visited[v]) continue;
        visited[v] = true;
        path.push_back(v);
        hamilton(v);
        path.pop_back();
        visited[v] = false;
    }
}

int main() {
    std::cin >> n >> m >> start;
    adj.assign(n + 1, std::vector<int>());
    visited.assign(n + 1, false);

    for (int i = 1; i <= m; ++i) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    visited[start] = true;
    path.push_back(start);
    hamilton(start);

    std::cout << result.size() << "\n";
    for (const auto &path : result) {
        for (const int &num : path) std::cout << num << " ";
        std::cout << "\n";
    }

    return 0;
}
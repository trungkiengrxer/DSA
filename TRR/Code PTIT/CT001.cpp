/*
(Tệp chương trình: CT.CPP; Thời gian chạy chương trình ≤ 1 giây)

Cho trước đồ thị vô hướng G = (V, E) gồm n đỉnh biểu diễn dưới dạng danh sách cạnh. Yêu cầu:

(1) Kiểm tra G có phải là đồ thị Euler, nửa Euler hay không?
(2) Tìm một chu trình Euler bắt đầu tại đỉnh u của G là đồ thị Euler.
Dữ liệu: Vào từ tệp CT.INP:

Dòng đầu chứa số nguyên dương t nhận giá trị 1 hoặc 2.
Nếu t = 1 thì dòng thứ 2 chứa hai số nguyên dương n là số đỉnh và m là số cạnh của G, với n <= 100, m <= n(n-1)/2. Nếu t = 2 thì dòng thứ 2 chứa ba số nguyên dương n, m và u, trong đó n là số đỉnh, m là số cạnh và u là một đỉnh của G, với 1 <= u <= n <= 100, m <= n(n-1)/2.
Trong m dòng tiếp theo, mỗi dòng thứi (1 <= i <=m) chứa chứa hai số nguyên ui,vi là đỉnh đầu và đỉnh cuối của cạnh ei, với 1 <= ui < vi <= n. Trong trường hợp t = 2 thì G là đồ thị Euler.
Kết quả: Ghi ra tệp CT.OUT:

Nếu t = 1 thì ghi ra giá trị 1 nếu G là Euler, giá trị 2 nếu G là nửa Euler và giá trị 0 nếu G không phải là Euler và nửa Euler.
Nếu t = 2 thì ghi ra trên một dòng gồm dãy các đỉnh mô tả chu trình Euler bắt đầu tại đỉnh u.
*/

#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <stack>
#include <vector>

int t, n, m, u;
std::vector<std::vector<int>> adj;
std::vector<int> visited;
std::stack<int> stack;
std::vector<int> euler;
void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (visited[v]) continue;
        dfs(v);
    }
}

void remove(int u, int v) {
    auto it = std::find(adj[u].begin(), adj[u].end(), v);
    if (it != adj[u].end()) adj[u].erase(it);

    it = std::find(adj[v].begin(), adj[v].end(), u);
    if (it != adj[v].end()) adj[v].erase(it);
}

void find_euler(int start) {
    stack.push(start);

    while (!stack.empty()) {
        int u = stack.top();

        if (!adj[u].empty()) {
            int v = adj[u].back();
            stack.push(v);
            remove(u, v);
        } else {
            stack.pop();
            euler.push_back(u);
        }
    }

    // std::reverse(euler.begin(), euler.end());
}

int main() {
    // std::ifstream std::cin("CT.INP");
    // std::ofstream std::cout("CT.OUT");

    std::cin >> t;

    if (t == 1)
        std::cin >> n >> m;
    else
        std::cin >> n >> m >> u;

    adj.resize(n + 1);
    visited.assign(n + 1, false);

    for (int i = 1; i <= m; ++i) {
        int a, b;
        std::cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    if (t == 1) {
        int start = 1;
        while (start <= n && adj[start].empty()) ++start;

        dfs(start);
        for (int i = 1; i <= n; ++i) {
            if (adj[i].size() > 0 && !visited[i]) {
                std::cout << 0;
                return 0;
            }
        }

        int count = 0;
        for (int i = 1; i <= n; ++i) {
            if (adj[i].size() % 2 != 0) ++count;
        }

        if (count == 0)
            std::cout << 1;
        else if (count == 2)
            std::cout << 2;
        else
            std::cout << 0;
    } else {
        find_euler(u);
        for (const int &v : euler) std::cout << v << " ";
    }

    return 0;
}
/*
(Tệp chương trình: CT.CPP; Thời gian chạy chương trình ≤ 1 giây)

Cho trước đồ thị vô hướng G = (V, E) gồm n đỉnh biểu diễn dưới dạng ma trận kề.

Yêu cầu:

(1) Kiểm tra G có phải là đồ thị Euler, nửa Euler hay không?

(2) Tìm một chu trình Euler bắt đầu tại đỉnh u của G là đồ thị Euler.

Dữ liệu: Vào từ tệp CT.INP:

Dòng đầu chứa số nguyên dương t nhận giá trị 1 hoặc 2.
Nếu t = 1 thì dòng thứ hai chứa số nguyên dương n là số đỉnh của G, n  100. Nếu t = 2 thì dòng thứ 2 chứa hai số nguyên dương n và u, trong đó n là số đỉnh và u là một đỉnh của G, 1 <= u <= n <= 100.
Trong n dòng tiếp theo, mỗi dòng chứa n số 0 hoặc 1 mô tả ma trận kề của G. Trong trường hợp t = 2 thì G là đồ thị Euler.
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

int n, u;
std::vector<std::set<int>> adj;
std::vector<int> euler;
std::vector<bool> visited;

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

void remove(int u, int v) {
    adj[u].erase(v);
    adj[v].erase(u);
}

void find_euler(int start) {
    std::stack<int> stack;
    stack.push(start);

    while (!stack.empty()) {
        int u = stack.top();

        if (!adj[u].empty()) {
            int v = *adj[u].begin();
            stack.push(v);
            remove(u, v);
        } else {
            stack.pop();
            euler.push_back(u);
        }
    }
}

int main() {
    int t;
    std::cin >> t;

    if (t == 1)
        std::cin >> n;
    else
        std::cin >> n >> u;

    adj.resize(n + 1);
    visited.assign(n + 1, false);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int x;
            std::cin >> x;
            if (x && i < j) {
                adj[i].insert(j);
                adj[j].insert(i);
            }
        }
    }

    if (t == 1) {
        int start = 0;
        while (start <= n && adj[start].empty()) ++start;

        if (start == 0) {
            std::cout << 1;
            return 0;
        }

        visited.assign(n + 1, false);
        dfs(start);

        for (int i = 1; i <= n; ++i) {
            if (!adj[i].empty() && !visited[i]) {
                std::cout << 0;
                return 0;
            }
        }

        int odd_count = 0;
        for (int i = 1; i <= n; ++i) {
            if (adj[i].size() % 2 != 0) {
                ++odd_count;
            }
        }

        if (odd_count == 0)
            std::cout << 1;
        else if (odd_count == 2)
            std::cout << 2;
        else
            std::cout << 0;
    } else {
        find_euler(u);
        std::reverse(euler.begin(), euler.end());

        for (const int &v : euler) {
            std::cout << v << " ";
        }
    }
    return 0;
}
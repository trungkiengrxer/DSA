/*
(Tệp chương trình: CT.CPP; Thời gian chạy chương trình ≤ 1 giây)

Cho trước đồ thị G = (V, E) gồm n đỉnh biểu diễn dưới dạng ma trận kề và một đỉnh u.

Yêu cầu: Tìm tất cả các chu trình Hamilton của G bắt đầu tại u.

Dữ liệu: Vào từ tệp CT.INP:

Dòng đầu chứa hai số nguyên dương n là số đỉnh và u là một đỉnh của G, 1 <= u <= n <= 100.
Trong n dòng tiếp theo, mỗi dòng chứa n số 0 hoặc 1 mô tả ma trận kề của G.
Kết quả: Ghi ra tệp CT.OUT:

Dòng đầu ghi giá trị t là số lượng các chu trình Hamilton tìm được.
Trong trường hợp t > 0, tiếp theo ghi ra t dòng, mỗi dòng ghi dãy các đỉnh của một chu trình Hamilton.
*/

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

int n, start;
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

    bool next = false;
    for (int v : adj[u]) {
        if (!visited[v]) {
            next = true;
            break;
        }
    }

    if (!next) return;

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
    std::ifstream input("CT.INP");
    std::ofstream print("CT.OUT");

    input >> n >> start;
    adj.assign(n + 1, std::vector<int>());
    visited.assign(n + 1, false);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int x;
            input >> x;
            if (x) adj[i].push_back(j);
        }
    }

    visited[start] = true;
    path.push_back(start);
    hamilton(start);

    for (const auto &path : result) {
        for (const int &num : path) print << num << " ";
        print << "\n";
    }

    print << result.size() << "\n";

    return 0;
}
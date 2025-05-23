/*
(Tệp chương trình: CT.CPP; Thời gian chạy chương trình ≤ 1 giây)

Cho trước đồ thị có trọng số G = (V, E) gồm n đỉnh biểu diễn dưới dạng ma trận trọng số không âm và một đỉnh u.

Yêu cầu: Tìm chu trình Hamilton của G bắt đầu tại u có tổng trọng số trên các cạnh là nhỏ nhất sử dụng thuật toán duyệt toàn thể.

Dữ liệu: Vào từ tệp CT.INP:

Dòng đầu chứa hai số nguyên dương n và u, trong đó n là số đỉnh, u là đỉnh của G, với 1 <= u <= n <= 100.
Trong n dòng tiếp theo, mỗi dòng thứ i chứa n số tự nhiên c[i][j] mô tả ma trận trọng số của G. Trong đó, với hai đỉnh i, j (i khác j) có cạnh nối thì 0 < c[i][j] <= 50, nếu không có cạnh nối thì c[i][j] = 10000 và c[i][i] = 0.
Kết quả: Ghi ra tệp CT.OUT:

Nếu tìm được chu trình Hamilton thỏa mãn yêu cầu thì ghi ra theo quy cách:
Dòng đầu ghi tổng trọng số của tất cả các cạnh trong chu trình Hamilton tìm được;
Dòng sau ghi dãy các đỉnh trên chu trình Hamilton tìm được bắt đầu từ u.
Nếu không có chu trình Hamilton thì ghi giá trị 0.
*/

#include <algorithm>
#include <iostream>
#include <vector>

const int INF = 10000;
int n, start;
std::vector<std::vector<int>> c;
std::vector<bool> visited;
std::vector<int> path, best_path;
int min_weight = INF * 100;

void hamilton(int u, int current_weight) {
    if (path.size() == n) { 
        if (c[u][start] != INF) {
            int total_weight = current_weight + c[u][start];
            if (total_weight < min_weight) {
                min_weight = total_weight;
                best_path = path;
                best_path.push_back(start);
            }
        }
        return;
    }

    for (int v = 1; v <= n; ++v) {
        if (!visited[v] && c[u][v] != INF) {
            visited[v] = true;
            path.push_back(v);
            hamilton(v, current_weight + c[u][v]);
            path.pop_back();
            visited[v] = false;
        }
    }
}


int main() {
    std::cin >> n >> start;
    c.assign(n + 1, std::vector<int>(n + 1));
    visited.assign(n + 1, false);

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) std::cin >> c[i][j];

    visited[start] = true;
    path.push_back(start);
    hamilton(start, 0);

    if (min_weight == INF * 100) {
        std::cout << 0;
    } else {
        std::cout << min_weight << "\n";
        for (const int &v : best_path) std::cout << v << " ";
    }

    return 0;
}

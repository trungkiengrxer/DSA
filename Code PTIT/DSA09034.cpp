/*
Sau khi thi trượt môn Cấu trúc dữ liệu và giải thuật, một số sinh viên D19 CNTT - PTIT quyết định bỏ học, đầu tư thuê đất để trồng rau. Mảnh đất thuê là một hình chữ nhật N x M (1≤ N≤ 100; 1≤ M≤ 100) ô đất hình vuông. Nhưng chỉ sau đó vài ngày, trận lụt khủng khiếp đã diễn ra làm một số ô đất bị ngập. Mảnh đất bỗng biến thành các cái ao. Và sinh viên D19 lại dự định chuyển sang nuôi cá. Các bạn ấy muốn biết mảnh đất được chia thành bao nhiêu cái ao để có thể tính toán nuôi cá cho hợp lý. Hãy giúp các bạn ấy nhé. Chú ý: Ao là gồm một số ô đất bị ngập có chung đỉnh. Dễ nhận thấy là một ô đất có thể có tối đa 8 ô chung đỉnh.

Dữ liệu vào: Dòng1: 2 số nguyên cách nhau bởi dấu cách: N và M. Dòng 2..N+1: M kí tự liên tiếp nhau mỗi dòng đại diện cho 1 hàng các ô đất.  Mỗi kí tự là 'W' hoặc '.' tương ứng với ô đất đã bị ngập và ô đất vẫn còn nguyên.

Kết quả:  Một dòng chứa 1 số nguyên duy nhất là số ao tạo thành.
*/

#include <iostream>
#include <vector>

int n, m;
std::vector<std::vector<char>> a;
std::vector<std::vector<bool>> visited;

int dx[8] = {0, 0, 1, -1, -1, -1, 1, 1};
int dy[8] = {1, -1, 0, 0, -1, 1, 1, -1};

bool is_valid(int i, int j) { return i >= 0 && i < n && j >= 0 && j < m && a[i][j] != '.'; }

void dfs(int i, int j) {
    visited[i][j] = true;
    for (int k = 0; k < 8; ++k) {
        int new_i = i + dx[k];
        int new_j = j + dy[k];

        if (!is_valid(new_i, new_j) || visited[new_i][new_j]) continue;
        dfs(new_i, new_j);
    }
}

int main() {
    std::cin >> n >> m;
    int count = 0;
    a.assign(n, std::vector<char>(m));
    visited.assign(n, std::vector<bool>(m, false));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) std::cin >> a[i][j];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (visited[i][j] || a[i][j] == '.') continue;
            dfs(i, j);
            ++count;
        }
    }

    std::cout << count << "\n";
}
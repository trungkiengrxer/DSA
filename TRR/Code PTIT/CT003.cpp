/*
(Tệp chương trình: CT.CPP; Thời gian chạy chương trình ≤ 1 giây)

Cho trước đồ thị có hướng G = (V, E) gồm n đỉnh biểu diễn dưới dạng danh sách kề.
Yêu cầu:
(1) Kiểm tra G có phải là đồ thị Euler, nửa Euler hay không?

(2) Tìm một chu trình Euler bắt đầu tại đỉnh u của G là đồ thị Euler.
Dữ liệu: Vào từ tệp CT.INP:

Dòng đầu chứa số nguyên dương t nhận giá trị 1 hoặc 2.
Nếu t = 1 thì dòng thứ hai chứa số nguyên dương n là số đỉnh của G, n <= 100. Nếu t = 2 thì dòng thứ 2 chứa hai số nguyên dương n và u, trong đó n là số đỉnh và u là một đỉnh của G, 1 <= u <= n <= 100.
Trong n dòng tiếp theo, mỗi dòng thứ i (1 <= i <= n) chứa số tự nhiên k là số lương đỉnh kề với đỉnh i và k số tự nhiên theo thứ tự tăng v1, ..., vk là số hiệu các đỉnh kề tương ứng. Trong trường hợp t = 2 thì G là đồ thị Euler.
Kết quả: Ghi ra tệp CT.OUT:

Nếu t = 1 thì ghi ra giá trị 1 nếu G là Euler, giá trị 2 nếu G là nửa Euler và giá trị 0 nếu G không phải là Euler và nửa Euler.
Nếu t = 2 thì ghi ra trên một dòng gồm dãy các đỉnh mô tả chu trình Euler bắt đầu tại đỉnh u.
*/

// #include <algorithm>
// #include <fstream>
// #include <iostream>
// #include <set>
// #include <stack>
// #include <vector>

// int n, u;
// std::vector<std::multiset<int>> adj;
// std::vector<std::multiset<int>> reversed;
// std::vector<int> euler;
// std::vector<bool> visited;

// void dfs(int u) {
//     visited[u] = true;
//     for (int v : adj[u]) {
//         if (visited[v]) continue;
//         dfs(v);
//     }
// }

// void reversed_dfs(int u) {
//     visited[u] = true;
//     for (int v : reversed[u]) {
//         if (visited[v]) continue;
//         reversed_dfs(v);
//     }
// }

// void remove(int u, int v) { adj[u].erase(v); }

// void find_euler(int start) {
//     std::stack<int> stack;
//     stack.push(start);

//     while (!stack.empty()) {
//         int u = stack.top();

//         if (!adj[u].empty()) {
//             int v = *adj[u].begin();
//             stack.push(v);
//             remove(u, v);
//         } else {
//             stack.pop();
//             euler.push_back(u);
//         }
//     }
// }

// int main() {
//     std::ifstream input("CT.INP");
//     std::ofstream print("CT.OUT");

//     int t;
//     input >> t;

//     if (t == 1)
//         input >> n;
//     else
//         input >> n >> u;

//     adj.assign(n + 1, std::multiset<int>());
//     reversed.resize(n + 1);
//     visited.assign(n + 1, false);

//     std::vector<int> deg_in(n + 1, 0);
//     std::vector<int> deg_out(n + 1, 0);

//     for (int i = 1; i <= n; ++i) {
//         int x;
//         input >> x;
//         for (int j = 1; j <= x; ++j) {
//             int k;
//             input >> k;
//             adj[i].insert(k);
//             reversed[k].insert(i);
//             ++deg_out[i];
//             ++deg_in[k];
//         }
//     }

//     if (t == 1) {
//         int start = 1;
//         while (start <= n && adj[start].empty()) ++start;

//         if (start == 1 || start > n) {
//             print << 1;
//             return 0;
//         }

//         dfs(start);
//         for (int i = 1; i <= n; ++i) {
//             if ((deg_in[i] > 0 || deg_out[i] > 0) && !visited[i]) {
//                 print << 0;
//                 return 0;
//             }
//         }

//         visited.assign(n + 1, false);
//         reversed_dfs(start);
//         for (int i = 1; i <= n; ++i) {
//             if ((deg_in[i] > 0 || deg_out[i] > 0) && !visited[i]) {
//                 print << 0;
//                 return 0;
//             }
//         }

//         int count1 = 0, count2 = 0;
//         for (int i = 1; i <= n; ++i) {
//             if (deg_in[i] != deg_out[i]) ++count1;
//             if (std::abs(deg_in[i] - deg_out[i]) > 1) ++count2;
//         }

//         if (count2 > 0)
//             print << 0;
//         else if (count1 == 0)
//             print << 1;
//         else if (count1 == 2)
//             print << 2;
//         else
//             print << 0;
//     } else {
//         find_euler(u);
//         // std::reverse(euler.begin(), euler.end());

//         for (const int &v : euler) {
//             print << v << " ";
//         }
//     }
//     return 0;
// }


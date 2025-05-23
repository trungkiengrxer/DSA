/*
Cho một hình hộp chữ nhật có kích thước A x B x C, trong đó A là chiều cao, B là chiều rộng và C là chiều dài. Mỗi ô có thể là một ô trống ‘.’ hoặc vật cản ‘#’.

Mỗi bước, bạn được phép di chuyển sang một ô kề bên cạnh (không được đi chéo). Nhiệm vụ của bạn là tìm đường đi ngắn nhất bắt đầu ‘S’ tới vị trí kết thúc ‘E’.

Input:

Dòng đầu tiên là số lượng bộ test T (1 ≤ N ≤ 50).
Mỗi test bắt đầu bởi 3 số nguyên A, B, C (A, B, C ≤ 30).
Tiếp theo là A khối, mỗi khối gồm B x C kí tự mô tả một lát cắt của hình hộp chữ nhật. Giữa 2 khối có một dấu xuống dòng.
Output:

In ra một số nguyên là đường đi ngắn nhất từ S tới E. Nếu không di chuyển được, in ra -1.
*/

#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <vector>

int dx[6] = {0, 0, 0, 0, -1, 1};
int dy[6] = {-1, 1, 0, 0, 0, 0};
int dz[6] = {0, 0, 1, -1, 0, 0};

bool found;
int a, b, c;
std::vector<std::vector<std::vector<char>>> mat;
std::vector<std::vector<std::vector<bool>>> visited;
std::vector<std::vector<std::vector<int>>> distance;

bool is_valid(int i, int j, int k) { return i >= 0 && i < a && j >= 0 && j < b && k >= 0 && k < c && !visited[i][j][k] && mat[i][j][k] != '#'; }

void bfs(int i, int j, int k) {
    visited[i][j][k] = true;
    std::queue<std::tuple<int, int, int>> queue;
    queue.push({i, j, k});

    while (!queue.empty()) {
        auto [i, j, k] = queue.front();
        queue.pop();
        for (int s = 0; s < 6; ++s) {
            int new_i = i + dx[s];
            int new_j = j + dy[s];
            int new_k = k + dz[s];

            if (!is_valid(new_i, new_j, new_k)) continue;
            visited[new_i][new_j][new_k] = true;
            queue.push({new_i, new_j, new_k});
            distance[new_i][new_j][new_k] = distance[i][j][k] + 1;

            if (mat[new_i][new_j][new_k] == 'E') {
                found = true;
                break;
            }
        }
        if (found) break;
    }
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        std::cin >> a >> b >> c;

        int start_i, start_j, start_k;
        int end_i, end_j, end_k;

        found = false;
        mat.assign(a, std::vector<std::vector<char>>(b, std::vector<char>(c)));
        visited.assign(a, std::vector<std::vector<bool>>(b, std::vector<bool>(c, false)));
        distance.assign(a, std::vector<std::vector<int>>(b, std::vector<int>(c, 0)));

        for (int i = 0; i < a; ++i) {
            for (int j = 0; j < b; ++j) {
                std::string s;
                std::cin >> s;

                for (int k = 0; k < c; ++k) {
                    mat[i][j][k] = s[k];
                    if (mat[i][j][k] == 'S') {
                        start_i = i;
                        start_j = j;
                        start_k = k;
                    } else if (mat[i][j][k] == 'E') {
                        end_i = i;
                        end_j = j;
                        end_k = k;
                    }
                }
            }
        }

        bfs(start_i, start_j, start_k);

        if (!found) {
            std::cout << "-1\n";
            continue;
        }
        std::cout << distance[end_i][end_j][end_k] << "\n";
    }
}
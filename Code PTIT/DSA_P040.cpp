/*
Cho một bảng kích thước 4 x N (gồm N cột). Mỗi ô (i, j) có điểm bằng A[i][j]. Bạn cần chọn một tập hợp các ô sao cho điểm đạt được là lớn nhất, và trong các ô được chọn, không có 2 ô nào có chung cạnh.

Ví dụ với bảng có N = 3 như hình vẽ trên. Cách chọn tập tối ưu là (3,1), (1, 2), (4, 2) và (3, 3).

Input:
Dòng đầu tiên là số lượng bộ test T (T <= 20).
Mỗi test bắt đầu bởi số nguyên dương N (1 <= N <= 10000).
4 dòng tiếp theo, mỗi dòng gồm N số A[i][j], là điểm tại ô (i,j) (-10000 <= A[i][j] <= 10000).

Output: 
Với mỗi test, in ra đáp án tìm được trên một dòng.
*/

#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<std::vector<int>> a(4, std::vector<int>(n));

        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < n; ++j) std::cin >> a[i][j];
        }

        
    }
}
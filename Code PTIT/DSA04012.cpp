/*
Cho hai đa thức P và Q được biểu diễn như một mảng bao gồm các hệ số của đa thức. Ví dụ với P(x) = 5 + 0x1 +10x2 + 6x3 được biểu diễn như mảng P[] ={5, 0, 10, 6}. Hãy đưa ra đa thức R = P×Q theo các hệ số của R với cách biểu diễn như trên.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm 3 dòng: dòng thứ nhất đưa vào hai số M, N tương ứng với lũy thừa lớn nhất của đa thức P và Q; dòng tiếp theo đưa vào M số là hệ số của đa thức P; dòng cuối cùng đưa vào M số là hệ số của đa thức Q.
T, M, N, P[i], Q[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤M, N≤100; 1≤P[i], Q[i]≤100.

Output:
Đưa ra kết quả mỗi test theo từng dòng.
*/

#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int m, n;
        std::cin >> m >> n;

        std::vector<int> a(m), b(n), result(m + n - 1);

        for (int i = 0; i < m; ++i) std::cin >> a[i];
        for (int i = 0; i < n; ++i) std::cin >> b[i];

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) result[i + j] += (a[i] * b[j]);
        }

        for (int i = 0; i < m + n - 1; ++i) std::cout << result[i] << " ";
        std::cout << "\n";
    }
}
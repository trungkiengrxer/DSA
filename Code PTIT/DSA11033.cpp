/*
Cho một lá cờ có kích thước N x M. Mỗi hàng được trang trí một dải huy hiệu từ vị trí (i, U[i]) tới (i, V[i]).

Cho Q truy vấn, mỗi truy vấn yêu cầu bạn cần xác định xem tại các vị trí cột C[1], C[2], …, C[Q] sẽ có bao nhiêu huy hiệu?

Input:
Dòng đầu tiên là số lượng hàng N.
Dòng tiếp theo gồm N cặp số (U[i], V[i]) cho biết mô tả của một dải huy hiệu.
Tiếp theo là số lượng truy vấn Q.
Dòng cuối gồm Q (Q ≤ 105) số nguyên C[1], C[2], …, C[Q].

Output: 
In ra Q dòng, dòng thứ i cho biết số lượng huy hiệu có trên vị trí cột C[i].

Giới hạn: 
Subtask 1 (40%): N ≤ 1000, 1 ≤ U[i], V[i] ≤ 1000.
Subtask 2 (40%): N ≤ 106, 1 ≤ U[i], V[i] ≤ 10^6.
Subtask 3 (20%): N ≤ 106, 1 ≤ U[i], V[i] ≤ 10^9.
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int main() {
    long long n, q;
    std::cin >> n;

    std::map<long long, long long> map;

    for (long long i = 0; i < n; ++i) {
        long long u, v;
        std::cin >> u >> v;
        ++map[u];
        --map[v + 1];
    }

    std::vector<std::pair<long long, long long>> a(map.begin(), map.end());

    std::map<long long, long long> sum;
    long long prefix = 0;

    for (const auto &[i, j] : map) {
        prefix += j;
        sum[i] = prefix;
    }

    std::cin >> q;

    while (q--) {
        long long c;
        std::cin >> c;

        auto it = sum.upper_bound(c);

        if (it == sum.begin()) {
            std::cout << "0\n";
            continue;
        }

        // std::cout << it -> first << "\n";
        --it;
        std::cout << it -> second << "\n";
    }
}
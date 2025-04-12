/*
Hãy in ra tất cả các xâu nhị phân độ dài N, có K bit 1 theo thứ tự từ điển tăng dần.

Input: Dòng đầu tiên là số lượng bộ test T (T ≤ 20). Mỗi test gồm 2 số nguyên N, K (1 ≤ K ≤ N ≤ 16).

Output:  Với mỗi test, in ra đáp án tìm được, mỗi xâu in ra trên một dòng.
*/

#include <iostream>
#include <vector>

bool is_valid(int n, int k, std::vector<int> &a) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 1) ++count;
        if (count > k) return false;
    }
    return count == k;
}

void binary_string(int n, int k, std::vector<int> &a) {
    while (true) {
        if (is_valid(n, k, a)) {
            for (int i = 0; i < n; ++i) std::cout << a[i];
            std::cout << "\n";
        }

        int i = n - 1;

        while (i >= 0 && a[i] == 1) {
            a[i] = 0;
            --i;
        }

        if (i < 0) return;
        a[i] = 1;
    }
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, k;
        std::cin >> n >> k;
        std::vector<int> a(n, 0);
        binary_string(n, k, a);
    }
}
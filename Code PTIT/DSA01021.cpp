/*
Cho số nguyên dương (1<N<40) và số nguyên dương K<N. Với 1 tổ hợp chập K phần tử của N, hãy cho biết tổ hợp tiếp theo sẽ có bao nhiêu phần tử mới. Nếu tổ hợp đã cho là cuối cùng thì kết quả là K.

Dữ liệu vào: Dòng đầu ghi số bộ test, không quá 20. Mỗi bộ test viết trên hai dòng
• Dòng 1: hai số nguyên dương N và K (K<N)
• Dòng 2 ghi K số của tổ hợp ban đầu. Theo đúng thứ tự tăng dần, không có số nào trùng nhau.

Kết quả: Với mỗi bộ dữ liệu in ra số lượng phần tử mới.
*/

#include <iostream>
#include <unordered_set>
#include <vector>

void next_combination(int n, int k, bool &finished, std::vector<int> &a) {
    int i = k - 1;
    while (i >= 0 && a[i] == n - k + i + 1) --i;

    if (i < 0) {
        finished = true;
        return;
    }
    ++a[i];
    for (int j = i + 1; j < k; ++j) a[j] = a[j - 1] + 1;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, k, count = 0;
        std::cin >> n >> k;

        std::vector<int> a(k);

        for (int i = 0; i < k; ++i) std::cin >> a[i];
        std::unordered_set<int> set(a.begin(), a.end());

        bool finished = false;
        next_combination(n, k, finished, a);

        if (finished) {
            std::cout << k << "\n";
            continue;
        }
        for (int i = 0; i < k; ++i) {
            if (set.find(a[i]) == set.end()) ++count;
        }

        std::cout << count << "\n";
    }
}
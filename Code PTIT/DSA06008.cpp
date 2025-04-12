/*
Cho mảng X[] gồm n phần tử và mảng Y[] gồm m phần tử. Hãy đếm số các cặp xy>yx, trong đó x€X[] và y€Y[]. Ví dụ X[] = {2, 1, 6 }, Y[] = {1, 5} ta có kết quả là 3 cặp (2, 1), (2, 5), (6, 1).

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm ba dòng: dòng đầu tiên đưa vào n, m tương ứng với số phần tử của mảng X[] và Y[]; dòng tiếp theo là n số X[i] của mảng X[]; dòng cuối cùng là m số của mảng Y[]; các số được viết cách nhau một vài khoảng trống.
T, n, m, X[i], Y[j] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n, m ≤10^5; 0≤ X[i], Y[j] ≤10^3.

Output:
Đưa ra kết quả mỗi test theo từng dòng.
*/

#include <algorithm>
#include <iostream>
#include <vector>

int count(int x, std::vector<int> &y, int m, std::vector<int> &exception) {
    if (x == 0) return 0;
    if (x == 1) return exception[0];

    auto it = std::upper_bound(y.begin(), y.end(), x);
    int result = y.end() - it;

    result += (exception[0] + exception[1]);

    if (x == 2) result -= (exception[3] + exception[4]);
    if (x == 3) result += (exception[2]);

    return result;
}

int count_pair(std::vector<int> &a, std::vector<int> &b, int &n, int &m) {
    int result = 0;

    std::vector<int> exception(5, 0);

    for (int i = 0; i < m; ++i) {
        if (b[i] <= 4) ++exception[b[i]];
    }

    for (int i = 0; i < n; ++i) {
        result += count(a[i], b, m, exception);
    }

    return result;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, m;
        std::cin >> n >> m;

        std::vector<int> a(n);
        std::vector<int> b(m);

        for (int i = 0; i < n; ++i) std::cin >> a[i];
        for (int i = 0; i < m; ++i) std::cin >> b[i];

        std::sort(b.begin(), b.end());

        std::cout << count_pair(a, b, n, m) << "\n";
    }
}
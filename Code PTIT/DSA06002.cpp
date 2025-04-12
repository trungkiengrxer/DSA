/*
Cho mảng A[] gồm n phần tử và số X. Hãy đưa sắp xếp các phần tử của mảng theo trị tuyệt đối của |X - A[i] |. Ví dụ với A[] = {10, 5, 3, 9, 2} và X = 7 ta đưa ra mảng được sắp xếp theo nguyên tắc kể trên: A[] = {5, 9, 10, 3, 2} vì |7-10|=3, |7-5|=2, |7-3|=4, |7-9|=2, |7-2|=5.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên là số phần tử của mảng n và X; dòng tiếp theo là n số A [i] của mảng A [];các số được viết cách nhau một vài khoảng trống.
T, n, X thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n, X, A[i] ≤10^5.

Output:
Đưa ra kết quả mỗi test theo từng dòng.
*/

#include <algorithm>
#include <iostream>
#include <vector>

int x;

bool comparator(int a, int b) {
    return std::abs(x - a) < std::abs(x - b);
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n >> x;

        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];

        std::stable_sort(a.begin(), a.end(), comparator);

        for (int i = 0; i < n; ++i) std::cout << a[i] << " ";
        std::cout << "\n";
    }
}
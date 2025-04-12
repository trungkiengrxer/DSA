/*
Cho mảng A[] gồm n phần tử. Nhiệm vụ của bạn là đưa ra mảng đã được sắp xếp bao gồm các chữ số của mỗi phần tử trong A[]. Ví dụ A[] = {110, 111, 112, 113, 114 }ta có kết quả là {0, 1, 2, 3, 4}.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào n là số phần tử của mảng A[]; dòng tiếp theo là n số A[i] ; các số được viết cách nhau một vài khoảng trống.
T, n, A[i] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n ≤10^7; 0≤ A[i] ≤10^16.

Output:
Đưa ra kết quả mỗi test theo từng dòng.
*/

#include <iostream>
#include <set>
#include <string>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<std::string> a(n);
        std::set<char> set;

        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            for (const char &c : a[i]) set.insert(c);
        }

        for (const char &num : set) std::cout << num << " ";
        std::cout << "\n";
    }
}
/*
Cho mảng A[] gồm n phần tử đã được sắp xếp. Hãy đưa ra 1 nếu X có mặt trong mảng A[], ngược lại đưa ra -1.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất đưa vào n, X là số các phần tử của mảng A[] và số X cần tìm; dòng tiếp theo đưa vào n số A[i] (1≤i≤n) các số được viết cách nhau một vài khoảng trống.
T, n, A, X thỏa mãn ràng buộc: 1≤T≤100; 1≤N, X, A[i] ≤10^6.

Output:
Đưa ra kết quả mỗi test theo từng dòng.
*/

#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, x;
        int found = -1;
        std::cin >> n >> x;

        std::vector<int> a(n);

        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            if (a[i] == x) found = 1;
        }

        std::cout << found << "\n";
    }
}
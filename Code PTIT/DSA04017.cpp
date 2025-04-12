/*
Cho hai mảng đã được sắp xếp A[] và B[] gồm N và N-1 phần tử. Các phần tử của mảng A[] chỉ khác mảng B[] một phần tử duy nhất. Hãy tìm vị trí của phần tử khác nhau giữa A[] và B[].

Input:
• Dòng đầu tiên đưa vào số lượng bộ test T.
• Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm 3 dòng: dòng thứ nhất đưa vào số N; dòng tiếp theo đưa vào N số của mảng A[];dòng tiếp theo đưa vào N-1 số của mảng B[]; các số được viết cách nhau một vài khoảng trống.
• T, N, A[i], B[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤ N≤10^7; 0≤ A[i]≤10^18.

Output:
• Đưa ra kết quả mỗi test theo từng dòng.
*/

#include <iostream>
#include <vector>

int find(std::vector<int> &a, std::vector<int> &b, int left, int right) {
    if (left == right) return left;

    int mid = (left + right) / 2;

    if (a[mid] != b[mid])
        return find(a, b, left, mid);
    else
        return find(a, b, mid + 1, right);
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> a(n), b(n - 1);

        for (int i = 0; i < n; ++i) std::cin >> a[i];
        for (int i = 0; i < n - 1; ++i) std::cin >> b[i];

        std::cout << find(a, b, 0, n - 2) + 1 << "\n";
    }
}
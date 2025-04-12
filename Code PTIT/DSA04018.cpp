/*
Cho mảng A[] gồm N phần tử chỉ bao gồm các số 0 và 1. Các số 0 được đặt trước các số 1. Hãy đếm các số 0 với thời gian log(N).

Input:
• Dòng đầu tiên đưa vào số lượng bộ test T.
• Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng thứ nhất đưa vào số N; dòng tiếp theo đưa vào N số của mảng A[]; các số được viết cách nhau một vài khoảng trống.
• T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤ N≤1000; 0≤ A[i]≤1.

Output:
• Đưa ra kết quả mỗi test theo từng dòng.
*/

#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];

        int left = 0, right = n - 1, result = n;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (a[mid] == 1) {
                result = mid;
                right = mid - 1;
            } else
                left = mid + 1;
        }

        std::cout << result << "\n";
    }
}
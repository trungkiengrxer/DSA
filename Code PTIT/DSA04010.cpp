/*
Cho mảng A[] gồm N số có cả các số âm và số dương. Nhiệm vụ của bạn là tìm mảng con liên tục có tổng lớn nhất của mảng. Ví dụ với mảng A[]={-2, -5, 6, -2,-3, 1, 5, -6} ta có kết quả là 7 tương ứng với dãy con {6, -2, -3, 1, 5}.

Input:
• Dòng đầu tiên đưa vào số lượng bộ test T.
• Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng thứ nhất đưa vào hai số N tương ứng với số phần tử của mảng; dòng tiếp theo đưa vào N số A[i]; các số được viết cách nhau một vài khoảng trống.
• T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤ N≤100; -100≤A[i] ≤100.

Output:
• Đưa ra tổng con liên tục lớn nhất của mỗi test theo từng dòng.
*/

#include <iostream>
#include <vector>

// int main() {
//     long long t;
//     std::cin >> t;

//     while (t--) {
//         long long n, max = -1e12;
//         std::cin >> n;

//         std::vector<long long> prefix(n);

//         for (long long i = 0; i < n; ++i) {
//             long long a;
//             std::cin >> a;

//             if (i == 0) {
//                 prefix[i] = a;
//                 continue;
//             }
//             prefix[i] = prefix[i - 1] + a;
//         }

//         for (long long i = 0; i < n; ++i) {
//             for (long long j = i; j < n; ++j) {
//                 long long sub_sum;

//                 if (i == 0) {
//                     sub_sum = prefix[j];
//                 } else
//                     sub_sum = prefix[j] - prefix[i - 1];
//                 max = std::max(sub_sum, max);
//             }
//         }

//         std::cout << max << "\n";
//     }
// }

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];

        int current_max = a[0], max = a[0];
        for (int i = 1; i < n; ++i) {
            current_max = std::max(current_max + a[i], a[i]);
            max = std::max(max, current_max);
        }

        std::cout << max << "\n";
    }
}
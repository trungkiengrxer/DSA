/*
Một con ếch có thể nhảy 1, 2, 3 bước để có thể lên đến một đỉnh cần đến. Hãy đếm số các cách con ếch có thể nhảy đến đỉnh.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là số n là số bước con ếch có thể lên được đỉnh.
T, n thỏa mãn ràng buộc: 1≤T≤100; 1≤n ≤50.

Output:
Đưa ra kết quả mỗi test theo từng dòng.
*/

#include <iostream>
#include <vector>

std::vector<long long> tribo(51);

void tribonacci() {
    tribo[0] = 1;
    tribo[1] = 1;
    tribo[2] = 2;
    for (long long i = 3; i < 51; ++i) tribo[i] = tribo[i - 1] + tribo[i - 2] + tribo[i - 3];
}

int main() {
    tribonacci();
    long long t;
    std::cin >> t;

    while (t--) {
        long long n;
        std::cin >> n;
        std::cout << tribo[n] << "\n";
    }
}
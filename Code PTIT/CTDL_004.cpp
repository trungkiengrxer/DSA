/*
Cho dãy gồm N số phân biệt AN = {a1, a2, .., aN } và số tự nhiên K (K<=N<=100). Ta gọi một dãy con tăng dần bậc K của dãy số AN là một dãy các số gồm K phần tử trong dãy đó thỏa mãn tính chất tăng dần. Bài toán được đặt ra là in ra màn hình  số các dãy con tăng dần bậc K của dãy số AN. Ví dụ :

Input:  5 3
2 5 15 10 20

Dòng đầu tiên ghi lại hai số N và K tương ứng với số phần tử của dãy số và bậc của dãy con.
Dòng kế tiếp : N số của dãy số AN, các số trong dãy không lớn hơn 100.

Output : 7 (số các dãy con tăng dần bậc 3 của dãy số AN)
*/

#include <iostream>
#include <vector>

void backtrack(int start, int n, int k, int &count, std::vector<int> &temp, std::vector<int> &a) {
    if (temp.size() == k) {
        ++count;
        return;
    }

    for (int i = start; i < n; ++i) {
        if (temp.empty() || a[i] > temp.back()) {
            temp.push_back(a[i]);
            backtrack(i + 1, n, k, count, temp, a);
            temp.pop_back();
        }
    }
}

int main() {
    int n, k, count = 0;
    std::cin >> n >> k;

    std::vector<int> a(n), temp;

    for (int i = 0; i < n; ++i) std::cin >> a[i];

    backtrack(0, n, k, count, temp, a);

    std::cout << count << "\n";
}
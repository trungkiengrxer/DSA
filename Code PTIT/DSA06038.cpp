/*
Cho dãy số nguyên A có n phần tử.

Hãy đếm xem có bao nhiêu cặp (i,j) thỏa mãn:

i < j
A[i] > A[j] và đều là số chẵn
Tồn tại chỉ số k với i < k < j sao cho A[k] là số lẻ

Input
Dòng đầu tiên ghi số n (1 ≤ n ≤ 10^5).

Output
Dòng thứ 2 ghi n số của dãy A, các giá trị A[i] không vượt quá 106.
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);

    for (int i = 0; i < n; ++i) std::cin >> a[i];
}
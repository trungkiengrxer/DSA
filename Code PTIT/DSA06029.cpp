/*
Cho dãy số A[] có n phần tử là các số nguyên dương. Hãy sắp xếp dãy số theo thuật toán sắp xếp chèn. Nhưng yêu cầu in ra lần lượt các bước chạy của thuật toán theo thứ tự ngược (bước cuối cùng in ra đầu tiên).

Input
Dòng đầu ghi số n (1 < n < 100)
Dòng thứ 2 ghi n số của dãy A (các số đều nguyên dương và nhỏ hơn 100000)

Output
Ghi ra lần lượt các bước thuật toán theo thứ tự ngược (xem ví dụ mẫu để hiểu rõ hơn).
*/

#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    std::vector<std::vector<int>> result;

    for (int i = 0; i < n; ++i) std::cin >> a[i];

    for (int i = 0; i < n; ++i) {
        int index = i;
        int new_value = a[i];

        while (index > 0 && a[index - 1] > new_value) {
            a[index] = a[index - 1];
            --index;
        }

        a[index] = new_value;

        result.push_back(a);
    }

    for (int i = result.size() - 1; i >= 0; --i) {
        std::cout << "Buoc " << i << ": ";
        for (int j = 0; j <= i; ++j) std::cout << result[i][j] << " ";
        std::cout << "\n";
    }
}
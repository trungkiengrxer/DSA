/*
Hãy thực hiện thuật toán sắp xếp chèn trên dãy N số nguyên. Ghi ra các bước thực hiện thuật toán.

Dữ liệu vào: Dòng 1 ghi số N (không quá 100). Dòng 2 ghi N số nguyên dương (không quá 100).

Kết quả: Ghi ra màn hình từng bước thực hiện thuật toán. Mỗi bước trên một dòng, các số trong dãy cách nhau đúng một khoảng trống.
*/

#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];

    for (int i = 0; i < n; ++i) {
        int index = i;
        int new_value = a[i];

        while (index > 0 && a[index - 1] > new_value) {
            a[index] = a[index - 1];
            --index;
        }

        a[index] = new_value;

        std::cout << "Buoc " << i << ": ";
        for (int j = 0; j <= i; ++j) std::cout << a[j] << " ";
        std::cout << "\n";
    }
}
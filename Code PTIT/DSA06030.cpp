/*
Cho dãy số A[] có n phần tử là các số nguyên dương. Hãy sắp xếp dãy số theo thuật toán sắp xếp nổi bọt. Nhưng yêu cầu in ra lần lượt các bước chạy của thuật toán theo thứ tự ngược (bước cuối cùng in ra đầu tiên).
Chú ý: thuật toán sắp xếp nổi bọt có thể kết thúc khi tất cả dãy đã sắp xếp, không còn cặp số cạnh nhau nào sai thứ tự.

Input
Dòng đầu ghi số bộ test (không quá 10). Mỗi test gồm 2 dòng:
Dòng đầu ghi số n (1 < n < 100)
Dòng thứ 2 ghi n số của dãy A (các số đều nguyên dương và nhỏ hơn 1000)

Output

Ghi ra lần lượt các bước thuật toán theo thứ tự ngược (xem ví dụ mẫu để hiểu rõ hơn).
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
        std::vector<std::vector<int>> result;

        for (int i = 0; i < n; ++i) std::cin >> a[i];

        for (int i = 0; i < n; ++i) {
            bool end = false;
            for (int j = 0; j < n - i - 1; ++j) {
                if (a[j] > a[j + 1]) {
                    std::swap(a[j], a[j + 1]);
                    end = true;
                }
            }

            if (!end) break;
            result.push_back(a);
        }

        for (int i = result.size() - 1; i >= 0; --i) {
            std::cout << "Buoc " << i + 1 << ": ";
            for (int j = 0; j < n; ++j) std::cout << result[i][j] << " ";
            std::cout << "\n";
        }
    }
}
/*
Hoàng yêu thích các số may mắn. Ta biết rằng một số là số may mắn nếu biểu diễn thập phân của nó chỉ chứa các chữ số may mắn là 4 và 7. Ví dụ, các số 47, 744, 4 là số may mắn và 5, 17, 467 không phải. Hoàng muốn tìm số may mắn bé nhất có tổng các chữ số bằng n. Hãy giúp anh ấy

Dữ liệu vào: Dòng đầu ghi số bộ test, mỗi bộ test có một dòng chứa số nguyên n (1 ≤ n ≤ 106) — tổng các chữ số của số may mắn cần tìm.

Kết quả: In ra trên 1 dòng số may mắn bé nhất, mà tổng các chữ số bằng n. Nếu không tồn tại số thỏa mãn, in ra -1.
*/

#include <iostream>
#include <string>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        bool found = false;

        std::cin >> n;

        int x = n / 7;

        for (int i = x; i >= 0; --i) {
            int y = n - i * 7;

            if (y % 4 == 0) {
                std::cout << std::string(y / 4, '4') << std::string(i, '7') << "\n";
                found = true;
                break;
            }
        }

        if (!found) std::cout << "-1\n";
    }
}
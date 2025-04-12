/*
Vương quốc PTIT sử dụng bảng chữ cái gồm N chữ cái Latinh viết hoa. Quy tắc đặt tên của gia đình Hoàng gia  PTIT là chọn ra K chữ cái (không trùng nhau) và sắp xếp lại theo thứ tự từ điển.
Hãy liệt kê tất cả các cái tên có thể có của gia đình Hoàng gia PTIT

Input
• Dòng đầu ghi số bộ test T (không quá 10)
• Mỗi bộ test ghi 2 số N và K (3 < K < N < 16)

Output
• Với mỗi bộ test, ghi ra tất cả các cái tên có thể được tạo ra, mỗi kết quả viết trên một dòng.
*/

#include <iostream>
#include <vector>

void backtrack(int start, int n, int k, std::vector<int> &result) {
    if (result.size() == k) {
        for (int num : result) std::cout << (char)(num + 64);
        std::cout << "\n";
        return;
    }

    for (int i = start; i <= n; ++i) {
        result.push_back(i);
        backtrack(i + 1, n, k, result);
        result.pop_back();
    }
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, k;
        std::cin >> n >> k;

        std::vector<int> result;
        backtrack(1, n, k, result);
    }
}
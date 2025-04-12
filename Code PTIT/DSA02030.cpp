/*
Cho chữ cái c in hoa (‘A’ < c < ’K’) và số nguyên K (0 < K < (c – ‘A’)).

Hãy tìm cách  liệt kê tất cả các xâu ký tự khác nhau được tạo ra bởi các chữ cái tính từ ‘A’ đến ký tự c. Các ký tự được phép lặp lại nhưng không tính các xâu là hoán vị của xâu nào đó đã liệt kê trước đó.

Xem ví dụ để hiểu thêm yêu cầu đề bài.

Input
Chỉ có một dòng ghi chữ cái c và số nguyên K thỏa mãn ràng buộc đề bài.

Output
Ghi ra lần lượt các xâu ký tự kết quả theo thứ tự từ điển, mỗi xâu trên một dòng.
*/

#include <iostream>
#include <string>
#include <vector>

void backtrack(int start, char c, int k, std::string &s) {
    if (s.size() == k) {
        std::cout << s << "\n";
        return;
    }

    for (int i = start; i <= c - 'A'; ++i) {
        s.push_back('A' + i);
        backtrack(i, c, k, s);
        s.pop_back();
    }
}

int main() {
    char c;
    int k;
    std::string s = "";

    std::cin >> c >> k;
    backtrack(0, c, k, s);
}
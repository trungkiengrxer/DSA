/*
Kỳ thi ICPC có K đội của PTIT tham gia và đội tuyển đang rất đau đầu không biết chọn các cái tên như thế nào cho các đội. Yêu cầu phải đảm bảo tên không có khoảng trống và không được trùng nhau. Sau khi thảo luận, có N cái tên được đề xuất (có thể bị trùng nhau). Với K<15 và 4 < N < 30.

Hãy liệt kê tất cả danh sách các tổ hợp K cái tên khác nhau có thể được tạo ra theo thứ tự từ điển.

Input
Dòng đầu ghi 2 số N và K.
Tiếp theo là 1 dòng ghi N cái tên, mỗi cái tên có độ dài không quá 15 và cách nhau một khoảng trống. Tất cả đều là ký tự in hoa.

Output
Ghi ra tất cả các tổ hợp tên có thể được lựa chọn theo thứ tự từ điển.
Tức là các tên trong mỗi tổ hợp liệt kê theo thứ tự từ điển và các tổ hợp cũng được liệt kê theo thứ tự từ điển.
*/

#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

void backtrack(int start, int n, int k, std::vector<std::string> &result, std::vector<std::string> &a) {
    if (result.size() == k) {
        for (const auto &string : result) std::cout << string << " ";
        std::cout << "\n";
        return;
    }

    for (int i = start; i < n; ++i) {
        result.push_back(a[i]);
        backtrack(i + 1, n, k, result, a);
        result.pop_back();
    }
}

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<std::string> a;
    std::vector<std::string> result;

    std::set<std::string> set;

    while (n--) {
        std::string s;
        std::cin >> s;
        set.insert(s);
    }

    for (const auto &element : set) a.push_back(element);

    backtrack(0, a.size(), k, result, a);
}
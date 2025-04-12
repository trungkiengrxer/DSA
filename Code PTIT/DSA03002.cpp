/*
Trong một buổi học toán, giáo viên viết 2 số nguyên, A và B, và yêu cầu Tèo thực hiện phép cộng. Tèo không bao giờ tính toán sai, nhưng thỉnh thoảng cậu ta chép các con số một cách không chính xác. Lỗi duy nhất của là ghi nhầm '5' thành '6' hoặc ngược lại.  Cho hai số, A và B, tính tổng nhỏ nhất và lớn nhất mà Tèo có thể nhận được.

Input: Có một dòng chứa hai số nguyên dương A và B ( 1 ≤ A, B ≤ 1 000 000).

Output: In ra 2 số nguyên cách nhau một dấu cách, tổng nhỏ nhất và lớn nhất có thể nhận được.
*/

#include <iostream>
#include <string>

void change(std::string &s, char a, char b) {
    for (char &c : s) {
        if (c == a) c = b;
    }
}

long long max(std::string a, std::string b) {
    change(a, '5', '6');
    change(b, '5', '6');
    return std::stoll(a) + std::stoll(b);
}

long long min(std::string a, std::string b) {
    change(a, '6', '5');
    change(b, '6', '5');
    return std::stoll(a) + std::stoll(b);
}

int main() {
    std::string a, b;
    std::cin >> a >> b;
    std::cout << min(a, b) << " " << max(a, b);
}
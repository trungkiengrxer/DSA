/*
Hãy viết chương trình nhận vào một chuỗi (có thể khá dài) các ký tự số và đưa ra màn hình hoán vị kế tiếp của các ký tự số đó (với ý nghĩa là hoán vị có giá trị lớn hơn tiếp theo nếu ta coi chuỗi đó là một giá trị số nguyên). Chú ý: Các ký tự số trong dãy có thể trùng nhau.

Ví dụ: 123 -> 132

279134399742 -> 279134423799

Cũng có trường hợp sẽ không thể có hoán vị kế tiếp. Ví dụ như khi đầu vào là chuỗi 987.

Dữ liệu vào: Dòng đầu tiên ghi số nguyên  t là số bộ test (1 ≤ t ≤ 1000).  Mỗi bộ test có một dòng, đầu tiên là số thứ tự bộ test, một dấu cách, sau đó là chuỗi các ký tự số, tối đa 80 phần tử.

Kết quả: Với mỗi bộ test hãy đưa ra một dòng gồm thứ tự bộ test, một dấu cách, tiếp theo đó là hoán vị kế tiếp hoặc chuỗi “BIGGEST” nếu không có hoán vị kế tiếp.
*/

#include <algorithm>
#include <iostream>
#include <string>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::string s;

        std::cin >> n;
        std::cin >> s;

        std::string temp = s;

        if (!std::next_permutation(temp.begin(), temp.end())) {
            std::cout << n << " BIGGEST\n";
            continue;
        }

        std::next_permutation(s.begin(), s.end());
        std::cout << n << " " << s << "\n";
    }
}
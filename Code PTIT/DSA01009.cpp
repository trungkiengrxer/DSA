/*
Một xâu kí tự S = (s1, s2, .., sn) được gọi là xâu AB độ dài n nếu với mọi siÎS thì si hoặc là kí tự A hoặc si là kí tự B . Ví dụ xâu S = “ABABABAB” là một xâu AB độ dài 8. Cho số tự nhiên N và số tự nhiên K (1£K<N£15 được nhập từ bàn phím), hãy viết chương trình liệt kê tất cả các xâu AB có độ dài N chứa duy nhất một dãy K kí tự A liên tiếp.

Dữ liệu vào chỉ có một dòng ghi hai số N và K.

Kết quả ghi ra màn hình theo khuôn dạng:

Dòng đầu tiên ghi lại số các xâu AB thỏa mãn yêu cầu bài toán;
Những dòng kế tiếp, mỗi dòng ghi lại một xâu AB thỏa mãn. Các xâu được ghi ra theo thứ tự từ điển.
*/

#include <iostream>
#include <string>
#include <vector>

bool is_valid(std::string &s, int k) {
    int count = 0, freq = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'A')
            ++freq;
        else
            freq = 0;

        if (freq == k && (s[i + 1] != 'A')) {
            ++count;
            freq = 0;
        }
    }

    return count == 1;
}

void backtrack(int n, int k, std::string &s, std::vector<std::string> &result) {
    if (s.size() == n) {
        if (is_valid(s, k)) {
            result.push_back(s);
        }
        return;
    }

    s.push_back('A');
    backtrack(n, k, s, result);
    s.pop_back();

    s.push_back('B');
    backtrack(n, k, s, result);
    s.pop_back();
}

int main() {
    int n, k;
    std::cin >> n >> k;

    std::string s = "";
    std::vector<std::string> result;

    backtrack(n, k, s, result);

    std::cout << result.size() << "\n";
    for (const std::string &s : result) std::cout << s << "\n";
}
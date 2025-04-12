/*
Cho một xâu ký tự S không có ký tự lặp lại. Hãy đưa ra tất cả các tập con của xâu ký tự S theo thứ tự từ điển.

Input:
Dòng đầu tiên đưa vào số lượng test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một xâu ký tự.
T, S thỏa mãn ràng buộc: 1≤T≤100; 1≤length(S)≤16.

Output:
Đưa ra kết quả mỗi test theo từng dòng.
*/

#include <iostream>
#include <string>
#include <vector>

void backtrack(int start, std::string &temp, std::string &s) {
    if (!temp.empty()) {
        std::cout << temp << " ";
    }

    for (int i = start; i < s.size(); ++i) {
        temp.push_back(s[i]);
        backtrack(i + 1, temp, s);
        temp.pop_back();
    }
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::string s;
        std::string temp = "";

        std::cin >> n;
        std::cin >> s;

        backtrack(0, temp, s);
        std::cout << "\n";
    }
}
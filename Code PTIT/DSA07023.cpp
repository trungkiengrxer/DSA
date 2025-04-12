/*
Cho xâu ký tự S. Nhiệm vụ của bạn là đảo ngược các từ trong S. Ví dụ S =  “I like this program very much”, ta nhận được kết quả là “much very program this like I”.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test là một xâu ký tự S.
T, S thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ Length(S)≤10^3.

Output:
Đưa ra kết quả mỗi test theo từng dòng.
*/

#include <iostream>
#include <sstream>
#include <stack>
#include <string>

int main() {
    int t;
    std::cin >> t;
    std::cin.ignore();

    while (t--) {
        std::string s;
        std::stack<std::string> stack;

        std::getline(std::cin, s);

        std::stringstream ss(s);
        std::string temp;

        while (ss >> temp) stack.push(temp);

        while (!stack.empty()) {
            std::cout << stack.top() << " ";
            stack.pop();
        }

        std::cout << "\n";
    }
}
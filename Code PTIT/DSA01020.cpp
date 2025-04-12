/*
Cho xâu nhị phân X[], nhiệm vụ của bạn là hãy đưa ra xâu nhị phân trước của X[]. Ví dụ X[] =”111111” thì xâu nhị phân trước của X[] là “111110”. Với xâu X[] =“000001” thì xâu nhị trước của X[] là “000000”. Chú ý: nếu xâu dữ liệu trong input là xâu đầu tiên thì trước nó sẽ là xâu cuối cùng.

Input:
• Dòng đầu tiên đưa vào số lượng test T.
• Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một xâu nhi phân X.
• T, X[] thỏa mãn ràng buộc: 1≤T≤100; 1≤length(X)≤10^3.

Output:
• Đưa ra kết quả mỗi test theo từng dòng.
*/

#include <iostream>
#include <string>
#include <vector>

void prev_binary_string(std::string &x) {
    int i = x.size() - 1;
    while (i >= 0 && x[i] == '0') {
        x[i] = '1';
        --i;
    }

    if (i < 0) return;
    x[i] = '0';
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        std::string x;
        std::cin >> x;

        prev_binary_string(x);

        std::cout << x << "\n";
    }
}
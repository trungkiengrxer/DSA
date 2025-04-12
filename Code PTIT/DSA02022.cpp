/*
Hôm nay là ngày 22/02/2022. Một ngày đặc biệt. Chỉ có hai chữ số là 0 và 2. Đồng thời viết xuôi viết ngược tám chữ số ta đều được cùng một kết quả.

Nhiệm vụ của bạn trong ngày đặc biệt này là hãy liệt kê hết tất cả các ngày hợp lệ chỉ có 2 chữ số 0 và 2.

Một số chú ý:
• Luôn có đủ 8 chữ số của ngảy tháng năm và hai dấu gạch chéo.
• Ngày và tháng có thể có chữ số 0 ở đầu nhưng với năm thì không được phép. Tức là ta chỉ tính các ngày bắt đầu từ năm 2000 trở về sau.

Bài toán không có dữ liệu vào. Bạn chỉ cần liệt kê kết quả gồm tất cả các ngày tháng hợp lệ. Coi dãy ký tự ngày tháng là một xâu ký tự. Hãy liệt kê theo đúng thứ tự từ điển tăng dần.
*/

#include <iostream>
#include <string>
#include <vector>

bool is_valid(std::string &s) {
    if (s[4] == '0') return false;
    if ((s[0] == '0' && s[1] == '0')  || (s[2] == '0' && s[3] == '0') || (s[2] == '2' && s[3] == '2') || s[2] == '2' && s[3] == '0') return false;
    return true;
}

void backtrack(int i, std::string &s, std::vector<std::string> &result) {
    if (i == 8) {
        if (is_valid(s)) result.push_back(s);
        return;
    }

    s[i] = '0';
    backtrack(i + 1, s, result);

    s[i] = '2';
    backtrack(i + 1, s, result);
}

int main() {
    std::string s;
    s.resize(8);

    std::vector<std::string> result;
    backtrack(0, s, result);

    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            std::cout << result[i][j];
            if (j == 1 || j == 3) std::cout << "/";
        }
        std::cout << "\n";
    }
}
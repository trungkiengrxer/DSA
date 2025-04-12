/*
Giả sử bạn là một người nghèo trong địa phương của bạn. Địa phương của bạn có duy nhất một cửa hàng bán lương thực. Cửa hàng của bạn mở cửa tất cả các ngày trong tuần ngoại trừ chủ nhật. Cho bộ ba số N, S, M thỏa mãn ràng buộc sau:
• N: số đơn vị lương thực nhiều nhất bạn có thể mua trong ngày.
• S: số lượng ngày bạn cần được sử dụng lương thực để tồn tại.
• M: số đơn vị lương thực cần có mỗi ngày để bạn tồn tại.

Giả sử bạn đang ở ngày thứ 2 trong tuần và cần tồn tại trong S ngày tới. Hãy cho biết số lượng ngày ít nhất bạn cần phải mua lương thực từ của hàng để tồn tại hoặc bạn sẽ bị chết đói trong S ngày tới.

Input:
• Dòng đầu tiên đưa vào số lượng bộ test T.
• Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là bộ 3 số N, S, M được viết trên một dòng.
• T, N, S, M thỏa mãn ràng buộc: 1≤T≤100;  1≤N, S, M ≤30.

Output:
• Đưa ra số ngày ít nhất bạn có thể mua lương thực để tồn tại hoặc đưa ra -1 nếu bạn bị chết đói.
*/

#include <iostream>

int main() {
    long long t;
    std::cin >> t;

    while (t--) {
        long long n, s, m, count = 0;

        std::cin >> n >> s >> m;

        long long total_day = (s / 7) * 6 + std::min((long long)6, s % 7);

        if (total_day * n < s * m) {
            std::cout << "-1\n";
            continue;
        }

        long long temp = 0;
        while (temp < s * m) {
            temp += n;
            ++count;
        }

        std::cout << count << "\n";
    }
}
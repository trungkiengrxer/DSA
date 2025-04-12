/*
Cho số tự nhiên N. Hãy tìm số nguyên dương X nhỏ nhất được tạo bởi số 9 và số 0 chia hết cho N. Ví dụ với N = 5 ta sẽ tìm ra  X = 90.

Input:
Dòng đầu tiên ghi lại số lượng test T (T≤100).
Những dòng kế tiếp mỗi dòng ghi lại một test. Mỗi test là một số tự nhiên N được ghi trên một dòng (N≤100).

Output:
Đưa ra theo từng dòng số X nhỏ nhất chia hết cho N tìm được .
*/

#include <iostream>
#include <queue>
#include <string>

int main() {
    long long t;
    std::cin >> t;

    while (t--) {
        long long n;
        std::cin >> n;

        std::queue<std::string> queue;
        queue.push("9");

        while (true) {
            std::string num = queue.front();
            if (std::stoll(num) % n == 0) {
                std::cout << num << "\n";
                break;
            }

            queue.pop();
            queue.push(num + "0");
            queue.push(num + "9");
        }
    }
}
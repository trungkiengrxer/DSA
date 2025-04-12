/*
Cho số tự nhiên n. Hãy in ra tất cả các số nhị phân từ 1 đến n.

Input:
Dòng đầu tiên ghi lại số lượng test T (T≤100).
Mỗi test là một số tự nhiên n được ghi trên một dòng (n≤10000).

Output:
Đưa ra kết quả mỗi test trên một dòng.
*/

#include <iostream>
#include <queue>
#include <string>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::queue<std::string> queue;
        queue.push("1");

        while (n) {
            std::string num = queue.front();
            std::cout << num << " ";
            --n;
            queue.pop();
            queue.push(num + "0");
            queue.push(num + "1");
        }

        std::cout << "\n";
    }
}
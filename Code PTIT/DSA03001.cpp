/*
Tại ngân hàng có các mệnh giá bằng 1, 2, 5, 10, 20, 50, 100, 200, 500, 1000. Tổng số tiền cần đổi có giá trị bằng N.  Hãy xác định xem có ít nhất bao nhiêu tờ tiền sau khi đổi tiền?

Input:
Dòng đầu tiên là số lượng bộ test T (T ≤ 50). Mỗi test gồm 1 số nguyên N ( 1 ≤ N ≤ 100 000).

Output: Với mỗi test, in ra đáp án trên một dòng.
*/

#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    std::vector<int> money = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};

    while (t--) {
        int n, count = 0;
        std::cin >> n;

        std::vector<int> value;

        for (int i = money.size() - 1; i >= 0; --i) {
            if (n >= money[i]) value.push_back(money[i]);
        }

        for (int num : value) {
            while (n >= num) {
                n -= num;
                ++count;
            }
        }

        std::cout << count << "\n";
    }
}
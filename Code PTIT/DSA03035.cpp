/*
Cho một dãy số a[] có n phần tử gồm các số từ 1 đến n theo 1 thứ tự ngẫu nhiên. Nhiệm vụ của bạn là sắp xếp lại dãy số này theo thứ tự tăng dần với điều kiện : ở mỗi bước sắp xếp, bạn chỉ được chọn 1 số ở 1 vị trí bất kì và chuyển số đó lên đầu dãy hoặc về cuối dãy.

Hãy tính số bước tối thiểu cần thực hiện để hoàn thành việc sắp xếp.

Input
• Dòng đầu tiên ghi 1 số n: số lượng phần tử của dãy a (1 ≤ n ≤ 100000)
• Dòng tiếp theo gồm n số từ 1 đến n theo thứ tự ngẫu nhiên

Output
• Một số nguyên duy nhất là số bước tối thiểu cần thực hiện để hoàn thành việc sắp xếp.
*/

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n, max_len = 0;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];

    std::vector<int> dp(*std::max_element(a.begin(), a.end()) + 1, 0);

    for (int i = 0; i < n; ++i) {
        dp[a[i]] = dp[a[i] - 1] + 1;
        max_len = std::max(max_len, dp[a[i]]);
    }

    std::cout << n - max_len;
}
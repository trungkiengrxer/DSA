/*
Một phân số đơn vị nếu tử số của phân số đó là 1. Mọi phân số nguyên dương đều có thể biểu diễn thành tổng các phân số đơn vị. Ví dụ 2/3 = 1/2  + 1/6. Cho phân số nguyên dương P/Q bất kỳ (P < Q), hãy biểu diễn phân số nguyên dương thành tổng phân số đơn vị với số hạng tử là ít nhất.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là bộ đôi tử số P và mẫu số Q của phân số nguyên dương được viết trên một dòng.
T, P, Q thỏa mãn ràng buộc: 1≤T≤100;  1≤P, Q≤100.

Output:
Đưa ra đáp án tìm được trên 1 dòng, theo dạng “1/a + 1/b + …”
*/

#include <cmath>
#include <iostream>
#include <vector>

int main() {
    long long t;
    std::cin >> t;

    while (t--) {
        long long p, q;
        std::vector<long long> frac;

        std::cin >> p >> q;

        while (p != 0) {
            long long a = std::ceil((long double)q / p);
            frac.push_back(a);

            p = p * a - q;
            q = q * a;
        }

        for (long long i = 0; i < frac.size(); ++i) {
            std::cout << "1/" << frac[i];
            if (i < frac.size() - 1) std::cout << " + ";
        }

        std::cout << "\n";
    }
}
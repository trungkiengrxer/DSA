/*
Cho một bảng kích thước vô hạn được chia làm lưới ô vuông đơn vị. Các hàng của bảng được đánh số từ 1 từ trên xuống và các cột của bảng được đánh số từ 1 từ trái qua phải. Ô nằm trên giao điểm của hàng i, và cột j được gọi là ô (i, j). Người ta điền các số nguyên liên tiếp bắt đầu từ 1 vào bảng theo quy luật sau:


Yêu cầu 1: Xác định giá trị ghi trên ô (x, y) của bảng
Yêu cầu 2: Xác định hàng và cột của ô chứa giá trị z.

Input:
Dòng đầu tiên là hai số nguyên x và y.
Dòng thứ hai chứa một số nguyên z.

Output:
Dòng đầu tiên in ra giá trị trên ô (x, y).
Dòng thứ hai in ra chỉ số hàng và cột của ô chứa giá trị z.

Giới hạn:
Subtask 1 (50%): x, y ≤ 1000, z ≤ 106;
Subtask 2 (50%): x, y, z ≤ 109.
*/

#include <iostream>
#include <cmath>

int main() {
    long long x, y, z;
    std::cin >> x >> y >> z;

    std::cout << ((x + y - 1) * (x + y)) / 2 - x + 1 << "\n";

    long long diag = (-1 + std::sqrt(8 * (long double)z - 7)) / 2 + 1;

    long long last_element = (diag * (diag + 1)) / 2;

    long long i = last_element - z + 1;
    long long j = diag - i + 1;

    std::cout << i << " " << j << "\n";

}
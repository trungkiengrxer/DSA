/*
Bài toán Tháp Hà Nội đã rất nổi tiểng. Bắt đầu có các đĩa xếp chồng lên cột A theo thứ tự kích thước giảm dần, nhỏ nhất ở trên cùng. Cột B và cột C ban đầu không có đĩa nào cả.

Mục tiêu của bạn là di chuyển toàn bộ các đĩa theo đúng thứ tự về cột C, tuân theo các quy tắc sau:

Mỗi lần chỉ có thể di chuyển một đĩa.
Mỗi lần di chuyển sẽ lấy đĩa trên từ một trong các cột và đặt nó lên trên một cột khác.
Không được đặt đĩa lên trên đĩa nhỏ hơn.

Input:
Số tự nhiên  0 < N < 10

Output:
In ra lần lượt từng bước theo mẫu trong ví dụ. Chú ý giữa các chữ cái và dấu -> có khoảng trống.
*/

#include <iostream>

void print(int &n, char &a, char &b) {
    std::cout << " " << a << " -> " << b << "\n";
}
void tower(int n, char &a, char &b, char &c) {
    if (n == 1) {
        print(n, a, c);
        return;
    }

    tower(n - 1, a, c, b);
    print(n, a, c);
    tower(n - 1, b, a, c);
}

int main() {
    int n;
    std::cin >> n;

    char a = 'A', b = 'B', c = 'C';
    tower(n, a, b, c);
}
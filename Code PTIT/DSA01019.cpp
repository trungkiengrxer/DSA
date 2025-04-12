/*
Khi chat chit vui vẻ, anh em chiến hữu thường hay gõ HAHA để thể hiện sự sảng khoái. Đôi khi cũng có thể gõ HAHAAAAA chẳng hạn cho thêm phần nhấn mạnh.

Giả sử một xâu ký tự được coi là HAHA nếu thỏa mãn các điều kiện:
• Ký tự đầu tiên phải là chữ H, ký tự cuối cùng phải là chữ A
• Không có hai chữ H nào liền nhau

Cho trước độ dài N, hãy liệt kê tất cả các xâu ký tự HAHA theo thứ tự từ điển.

Input
• Dòng đầu ghi số bộ test T (không quá 10)
• Mỗi bộ test ghi độ dài N (2 <= N < 16)

Output
Với mỗi bộ test, ghi ra tất cả các xâu HAHA tìm được theo thứ tự từ điển, mỗi xâu viết trên một dòng.
*/

#include <iostream>
#include <vector>

bool is_valid(int n, std::vector<char> &a) {
    if (a[0] != 'H' || a[n - 1] != 'A') return false;
    for (int i = 1; i < n; ++i) {
        if (a[i] == 'H' && a[i - 1] == 'H') return false;
    }

    return true;
}

void binary_string(int n, std::vector<char> &a) {
    while (true) {
        if (is_valid(n, a)) {
            for (int i = 0; i < n; ++i) std::cout << a[i];
            std::cout << "\n";
        }

        int i = n - 1;
        while (i >= 0 && a[i] == 'H') {
            a[i] = 'A';
            --i;
        }

        if (i < 0) return;
        a[i] = 'H';
    }
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<char> a(n, 'A');
        binary_string(n, a);
    }
}
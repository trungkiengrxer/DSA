/*
Cho mảng A[] gồm N số và thực hiện các thao tác theo nguyên tắc dưới đây:

Ta chọn một mảng con sao cho phần tử ở giữa của mảng con cũng là phần tử ở giữa của mảng A[] (trong trường hợp N lẻ).
Đảo ngược mảng con đã chọn trong mảng A[]. Ta được phép chọn mảng con và phép đảo ngược mảng con bao nhiêu lần tùy ý.
Ví dụ với mảng A[] = {1, 6, 3, 4, 5, 2, 7} ta có câu trả lời là Yes vì: ta chọn mảng con {3, 4, 5} và đảo ngược để nhận được mảng A[]={1, 6, 5, 4, 3, 2, 7}, chọn tiếp mảng con {6, 5, 4, 3, 2} và đảo ngược ta nhận được mảng A[]={1, 2, 3, 4, 5, 6, 7}. Hãy cho biết ta có thể sắp xếp được mảng A[] bằng cách thực hiện các thao tác kể trên hay không?

Input:
• Dòng đầu tiên đưa vào số lượng bộ test T.
• Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng thứ nhất đưa vào số phần tử của mảng N; dòng tiếp theo đưa vào N số A[i] tương ứng với các phần tử của mảng A[]; các số được viết cách nhau một vài khoảng trống.
• T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤ N ≤50; 0≤A[i]≤1000.

Output:
• Đưa ra kết quả mỗi test theo từng dòng.
*/

#include <algorithm>
#include <iostream>
#include <vector>

bool is_valid(int n, std::vector<int> &a, std::vector<int> &b) {
    for (int i = 0; i < n; ++i) {
        if (b[i] != a[i] && b[n - i - 1] != a[i]) return false;
    }
    return true;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> a(n);
        std::vector<int> b(n);

        for (int i = 0; i < n; ++i) std::cin >> a[i];
        b = a;

        std::sort(b.begin(), b.end());

        if (is_valid(n, a, b))
            std::cout << "Yes";
        else
            std::cout << "No";
        std::cout << "\n";
    }
}
/*
Tại Chương Mỹ Resort, vào nửa đêm, cả trung đội nhận lệnh tập trung ở sân. Mỗi chiến sỹ được đánh số từ 1 đến N (1<N<40). Giám thị yêu cầu chọn ra một dãy K chiến sỹ để tập đội ngũ và cứ lần lượt duyệt hết tất cả các khả năng chọn K người như vậy từ nhỏ đến lớn (theo số thứ tự). Bài toán đặt ra là cho một nhóm K chiến sỹ hiện đang phải tập đội ngũ, hãy tính xem trong lượt chọn K người tiếp theo thì mấy người trong nhóm cũ sẽ được tạm nghỉ. Nếu đã là nhóm cuối cùng thì tất cả đều sẽ được nghỉ.

Dữ liệu vào: Dòng đầu ghi số bộ test, không quá 20. Mỗi bộ test viết trên hai dòng

Dòng 1: hai số nguyên dương N và K (K<N)
Dòng 2 ghi K số thứ tự của các chiến sỹ đang phải tập đội ngũ (viết từ nhỏ đến lớn)

Kết quả: Với mỗi bộ dữ liệu in ra số lượng chiến sỹ được tạm nghỉ.
*/

#include <algorithm>
#include <iostream>
#include <vector>

void next_combination(int n, int k, std::vector<int> &a) {
    int i = k - 1;
    while (i >= 0 && a[i] == n - k + i + 1) --i;
    if (i < 0) return;
    ++a[i];
    for (int j = i + 1; j < k; ++j) a[j] = a[j - 1] + 1;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, k, count = 0;
        std::cin >> n >> k;

        std::vector<int> a(k);

        for (int i = 0; i < k; ++i) std::cin >> a[i];

        std::vector<int> temp = a;
        next_combination(n, k, a);

        if (temp == a) {
            std::cout << k << "\n";
            continue;
        }

        for (int i = 0; i < k; ++i) {
            if (std::binary_search(a.begin(), a.end(), temp[i])) ++count;
        }

        std::cout << k - count << "\n";
    }
}
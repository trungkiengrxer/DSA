/*
Ban đầu cho một queue rỗng. Bạn cần thực hiện các truy vấn sau:

1. Trả về kích thước của queue
2. Kiểm tra xem queue có rỗng không, nếu có in ra “YES”, nếu không in ra “NO”.
3. Cho một số nguyên và đẩy số nguyên này vào cuối queue.
4. Loại bỏ phần tử ở đầu queue nếu queue không rỗng, nếu rỗng không cần thực hiện.
5. Trả về phần tử ở đầu queue, nếu queue rỗng in ra -1.
6. Trả về phần tử ở cuối queue, nếu queue rỗng in ra -1.

Dữ liệu vào
Dòng đầu tiên chứa số nguyên T là số bộ dữ liệu, mỗi bộ dữ theo dạng sau.
Dòng đầu tiên chứa số nguyên n - lượng truy vấn (1 ≤ n ≤ 1000)
N dòng tiếp theo, mỗi dòng sẽ ghi loại truy vấn như trên, với truy vấn loại 3 sẽ có thêm một số nguyên, không quá 106.

Kết quả: In ra kết quả của các truy vấn..
*/

#include <iostream>
#include <queue>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int q;
        std::cin >> q;

        std::queue<int> queue;

        while (q--) {
            int n;
            std::cin >> n;

            switch (n) {
                case 1:
                    std::cout << queue.size() << "\n";
                    break;
                case 2:
                    if (!queue.empty())
                        std::cout << "NO\n";
                    else
                        std::cout << "YES\n";
                    break;
                case 3:
                    int x;
                    std::cin >> x;
                    queue.push(x);
                    break;
                case 4:
                    if (queue.empty()) continue;
                    queue.pop();
                    break;
                case 5:
                    if (queue.empty()) {
                        std::cout << "-1\n";
                        continue;
                    }
                    std::cout << queue.front() << "\n";
                    break;
                case 6:
                    if (queue.empty()) {
                        std::cout << "-1\n";
                        continue;
                    }
                    std::cout << queue.back() << "\n";
                    break;
                default:
                    break;
            }
        }
    }
}
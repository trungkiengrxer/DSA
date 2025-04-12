/*
Cho ba số N, P, S. Trong đó, P là một số nguyên tố. Nhiệm vụ của bạn là đưa ra tất cả N số nguyên tố lớn hơn P có tổng bằng S. Ví dụ với S = 28, P=7, N =2 ta có kết quả 11 + 17 = 28. Với N = 3, P = 2, S = 23 ta có kết quả : {3, 7, 13}, {5, 7, 11}

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là bộ ba số S, P, N được viết trên một dòng.
S, P, N thỏa mãn ràng buộc: 1≤T ≤100; 1 ≤ N ≤ 10; 2≤S, P≤200.

Output:
Với mỗi test, dòng đầu tiên in ra số lượng đáp án tìm được. Mỗi dòng tiếp theo in ra kết quả tìm được theo thứ tự từ điển.
*/

#include <iostream>
#include <vector>

std::vector<bool> prime(201, true);

void sieve() {
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= 201; ++i) {
        if (prime[i])
            for (int j = i * i; j < 201; j += i) prime[j] = false;
    }
}

void backtrack(int start, int sum, int &n, int &s, std::vector<int> &container, std::vector<int> &temp, std::vector<std::vector<int>> &result) {
    if (sum == s && temp.size() == n) {
        result.push_back(temp);
        return;
    }
    if (sum > s || temp.size() > n) return;

    for (int i = start; i < container.size(); ++i) {
        temp.push_back(container[i]);
        backtrack(i + 1, sum + container[i], n, s, container, temp, result);
        temp.pop_back();
    }
}

int main() {
    sieve();
    int t;
    std::cin >> t;

    while (t--) {
        int s, p, n;
        std::cin >> n >> p >> s;

        std::vector<int> container;
        std::vector<int> temp;
        std::vector<std::vector<int>> result;

        for (int i = p + 1; i < s; ++i) {
            if (prime[i]) container.push_back(i);
        }

        backtrack(0, 0, n, s, container, temp, result);

        std::cout << result.size() << "\n";
        for (const auto &vector : result) {
            for (const int &num : vector) std::cout << num << " ";
            std::cout << "\n";
        }
    }
}
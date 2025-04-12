/*
Cho ma trận vuông A kích thước N x N. Nhiệm vụ của bạn là hãy tính ma trận X = AK với K là số nguyên cho trước. Sau đó, tính tổng các phần tử của cột cuối cùng. Đáp số có thể rất lớn, hãy in ra kết quả theo modulo 109+7.

Input:
Dòng đầu tiên là số lượng bộ test T (T ≤ 100).
Mỗi test bắt gồm một số nguyên N và K (1 ≤ N ≤ 10, 1 ≤ K ≤ 10^9) là kích thước của ma trận và số mũ.

Output:
Với mỗi test, in ra kết quả của ma trận X.
*/

#include <iostream>
#include <vector>

const long long MOD = 1e9 + 7;

class Matrix {
   public:
    std::vector<std::vector<long long>> mat;
    long long capacity;

    Matrix(long long n) {
        mat.resize(n, std::vector<long long>(n, 0));
        capacity = n;
    }

    long long size() { return capacity; }

    friend Matrix operator*(Matrix &a, Matrix &b) {
        Matrix result(a.size());
        for (long long i = 0; i < a.size(); ++i) {
            for (long long j = 0; j < b.size(); ++j) {
                result.mat[i][j] = 0;
                for (long long k = 0; k < result.size(); ++k) {
                    result.mat[i][j] += a.mat[i][k] * b.mat[k][j];
                    result.mat[i][j] %= MOD;
                }
            }
        }
        return result;
    }

    friend std::istream &operator>>(std::istream &cin, Matrix &a) {
        for (long long i = 0; i < a.size(); ++i) {
            for (long long j = 0; j < a.size(); ++j) {
                cin >> a.mat[i][j];
            }
        }
        return cin;
    }

    Matrix pow(Matrix &a, long long exp) {
        Matrix result(a.size());

        for (int i = 0; i < result.size(); ++i) result.mat[i][i] = 1;

        while (exp > 0) {
            if (exp % 2) result = result * a;
            a = a * a;
            exp /= 2;
        }

        return result;
    }
};

int main() {
    long long t;
    std::cin >> t;

    while (t--) {
        long long n, k, sum = 0;
        std::cin >> n >> k;

        Matrix a(n);
        std::cin >> a;

        Matrix result = a.pow(a, k);

        for (long long i = 0; i < n; ++i) sum = (sum + result.mat[i][n - 1]) % MOD;

        std::cout << sum << "\n";
    }
}
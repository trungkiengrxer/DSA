#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - i; ++j) {
            int diag = i + j;
            int value = (diag * (diag + 1)) / 2 + 1 + j;
            cout << value << " ";
        }
        cout << endl;
    }

    int i, j;
    std::cin >> i >> j;

    int diag = i + j;
    // Công thức tính giá trị tại vị trí (i,j)
    int value = (diag * (diag + 1)) / 2 + 1 + j;
    cout << value << " ";

    return 0;
}

/*
#include <iostream>
#include <cmath>
using namespace std;

pair<long long, long long> findCoordinates(long long value) {
    // Tính đường chéo bằng phương pháp giải phương trình bậc 2
    // Formula: diag^2 + diag - 2*(value-1) = 0
    // Nghiệm: diag = (-1 + sqrt(1 + 8*(value-1)))/2
    long double discriminant = 1 + 8.0L * (value - 1);
    long long diag = (long long)((-1 + sqrt(discriminant)) / 2);

    // Kiểm tra xem đường chéo đã chính xác chưa
    // Nếu có lỗi làm tròn, chúng ta sẽ điều chỉnh
    long long firstValueOnDiag = diag * (diag + 1LL) / 2 + 1LL;

    if (firstValueOnDiag > value) {
        diag--; // Điều chỉnh nếu vượt quá
        firstValueOnDiag = diag * (diag + 1LL) / 2 + 1LL;
    }

    // Tính offset trên đường chéo
    long long offset = value - firstValueOnDiag;

    // Tính tọa độ
    long long j = offset;
    long long i = diag - j;

    return {i, j};
}

int main() {
    long long value;
    cout << "Nhập giá trị cần tìm tọa độ: ";
    cin >> value;

    // Kiểm tra giới hạn đầu vào
    if (value <= 0) {
        cout << "Giá trị phải lớn hơn 0!" << endl;
        return 1;
    }

    pair<long long, long long> coords = findCoordinates(value);
    cout << "Tọa độ của giá trị " << value << " là: ("
         << coords.first << ", " << coords.second << ")" << endl;

    return 0;
}
*/
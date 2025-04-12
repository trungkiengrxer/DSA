#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    string s;
    cin >> s;
    
    // Đếm số viên bi của mỗi màu
    int countX = 0, countT = 0, countD = 0;
    for (char c : s) {
        if (c == 'X') countX++;
        else if (c == 'T') countT++;
        else if (c == 'D') countD++;
    }
    
    // Tạo 3 mảng để chứa các viên bi của từng loại
    // Mảng 1: từ 0 đến countX-1 là các viên bi xanh (X)
    // Mảng 2: từ countX đến countX + countT - 1 là các viên bi trắng (T)
    // Mảng 3: từ countX + countT đến N-1 là các viên bi đỏ (D)
    
    int swapCount = 0;
    
    // Đếm số lần đổi chỗ giữa các nhóm
    vector<int> X, T, D;
    
    // Tạo các chỉ số của các viên bi không đúng vị trí
    for (int i = 0; i < countX; i++) {
        if (s[i] != 'X') {
            if (s[i] == 'T') T.push_back(i);
            else if (s[i] == 'D') D.push_back(i);
        }
    }
    for (int i = countX; i < countX + countT; i++) {
        if (s[i] != 'T') {
            if (s[i] == 'X') X.push_back(i);
            else if (s[i] == 'D') D.push_back(i);
        }
    }
    for (int i = countX + countT; i < N; i++) {
        if (s[i] != 'D') {
            if (s[i] == 'X') X.push_back(i);
            else if (s[i] == 'T') T.push_back(i);
        }
    }
    
    // Swap giữa các nhóm
    swapCount = X.size() + T.size() + D.size() ;
    
    // In kết quả
    cout << swapCount << endl;

    return 0;
}

/*
Trên trục Ox tính từ vị trí 0, người ta muốn xếp nhiều nhất các đoạn thẳng sao cho không đoạn nào chồng lấn lên nhau. Đoạn thẳng thứ i có vị trí bắt đầu là X1[i] và kết thúc tại X2[i], với X1[i] <= X2[i].

Hãy tính số đoạn thẳng nhiều nhất có thể được lựa chọn để đưa lên trục Ox và không có đoạn nào chồng lấn lên nhau.

Input
Dòng đầu tiên ghi số bộ test, không quá 10.
Với mỗi bộ test: dòng đầu ghi số N là số đoạn thẳng (không quá 105)
Tiếp theo là N dòng, mỗi dòng có 2 số nguyên mô tả đoạn thẳng. Các giá trị tọa độ đều là các số nguyên không âm và không quá 106.

Output
Với mỗi test, viết trên 1 dòng số lượng đoạn thẳng nhiều nhất có thể được lựa chọn thỏa mãn điều kiện đề bài.
*/

#include <algorithm>
#include <iostream>
#include <vector>

bool comparator(std::pair<long long, long long> &a, std::pair<long long, long long> &b) { return a.second < b.second; }

int main() {
    long long t;
    std::cin >> t;

    while (t--) {
        long long n;
        std::cin >> n;

        std::vector<std::pair<long long, long long>> lines;

        for (long long i = 0; i < n; ++i) {
            long long x, y;
            std::cin >> x >> y;
            lines.push_back({x, y});
        }

        std::sort(lines.begin(), lines.end(), comparator);

        long long count = 1, end_pos = lines[0].second;

        for (long long i = 1; i < n; ++i) {
            if (lines[i].first < end_pos) continue;
            ++count;
            end_pos = lines[i].second;
        }

        std::cout << count << "\n";
    }
}
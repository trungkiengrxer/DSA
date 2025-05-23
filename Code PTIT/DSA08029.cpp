/*
Có một chiếc bảng hình chữ nhật với 6 miếng ghép, trên mỗi miếng ghép được điền một số nguyên trong khoảng từ 1 đến 6. Tại mỗi bước, chọn một hình vuông (bên trái hoặc bên phải), rồi quay theo chiều kim đồng hồ.

Yêu cầu: Cho một trạng thái của bảng, hãy tính số phép biến đổi ít nhất để đưa bảng đến trạng thái đích.

Input:

Dòng đầu ghi số bộ test (không quá 10). Mỗi bộ test gồm hai dòng:
Dòng đầu tiên chứa 6 số là trạng thái bảng ban đầu (thứ tự từ trái qua phải, dòng 1 tới dòng 2).
Dòng thứ hai chứa 6 số là trạng thái bảng đích (thứ tự từ trái qua phải, dòng 1 tới dòng 2).
Output: 

Với mỗi test, in ra một số nguyên là đáp số của bài toán.
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <string>

std::string start;
std::string end;

std::string rotate_left(std::string a) {
    std::string temp = a;
    temp[0] = a[3];
    temp[1] = a[0];
    temp[2] = a[2];
    temp[3] = a[4];
    temp[4] = a[1];
    temp[5] = a[5];
    a = temp;
    return a;
}

std::string rotate_right(std::string a) {
    std::string temp = a;
    temp[0] = a[0];
    temp[1] = a[4];
    temp[2] = a[1];
    temp[3] = a[3];
    temp[4] = a[5];
    temp[5] = a[2];
    a = temp;
    return a;
}

int bfs() {
    std::queue<std::string> queue;
    std::unordered_map<std::string, int> map;

    map[start] = 0;
    queue.push(start);

    while (!queue.empty()) {
        std::string top = queue.front();
        queue.pop();
        int distance = map[top];

        std::string left = rotate_left(top);
        if (!map.count(left)) {
            map[left] = distance + 1;
            if (left == end) return map[left];
            queue.push(left);
        }
        
        std::string right = rotate_right(top);
        if (!map.count(right)) {
            map[right] = distance + 1;
            if (right == end) return map[right];
            queue.push(right);
        }

    }
    return -1;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        start.clear();
        end.clear();

        for (int i = 0; i < 6; ++i) {
            char c;
            std::cin >> c;
            start.push_back(c);
        }

        for (int i = 0; i < 6; ++i) {
            char c;
            std::cin >> c;
            end.push_back(c);
        }

        std::cout << bfs() << "\n";
    }
}
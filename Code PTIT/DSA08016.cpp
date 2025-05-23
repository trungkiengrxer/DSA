/*
HEXGAME là một trò chơi xếp hình gồm 10 miếng ghép hình lục giác đều, trên mỗi miếng ghép được điền một số nguyên, có 8 miếng được điền số  từ 1 đến 8 và có hai miếng điền số 0. Các miếng liên kết với nhau tạo thành lưới tổ ong. Ban đầu các miếng ghép ở vị trí như hình vẽ. Tại mỗi bước, chọn một miếng ghép có đúng 6 miếng ghép kề cạnh làm tâm, rồi xoay một nấc 6 miếng ghép kề cạnh đó theo chiều kim đồng hồ. Như vậy chỉ có hai cách chọn tâm, đó là chọn tâm bên trái và chọn tâm bên phải.

Yêu cầu: Cho một trạng thái của trò chơi (nhận được sau một dãy biến đổi từ trạng thái ban đầu), hãy tính số phép biến đổi ít nhất để đưa về trạng thái ban đầu.

Input:

Dòng đầu ghi số bộ test (không quá 10). Mỗi bộ test gồm:
Dòng đầu tiên chứa 3 số ở 3 miếng ghép dòng thứ nhất (thứ tự từ trái qua phải).
Dòng thứ hai chứa 4 số ở 4 miếng ghép dòng thứ hai (thứ tự từ trái qua phải).
Dòng thứ 3 chứa 3 số ở 3 miếng ghép dòng thứ ba (thứ tự từ trái qua phải).
Output:

Với mỗi bộ test in ra một số nguyên là số phép biến đổi ít nhất để đưa được về trạng thái ban đầu.
*/

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

std::string end, start = "1238004765";

std::string rotate_left(std::string end) {
    std::string result = end;
    result[0] = end[3];
    result[1] = end[0];
    result[2] = end[2];
    result[3] = end[7];
    result[4] = end[4];
    result[5] = end[1];
    result[6] = end[6];
    result[7] = end[8];
    result[8] = end[5];
    result[9] = end[9];
    return result;
}

std::string rotate_right(std::string end) {
    std::string result = end;
    result[0] = end[0];
    result[1] = end[4];
    result[2] = end[1];
    result[3] = end[3];
    result[4] = end[8];
    result[5] = end[5];
    result[6] = end[2];
    result[7] = end[7];
    result[8] = end[9];
    result[9] = end[6];
    return result;
}

int bfs() {
    std::queue<std::string> queue;
    std::unordered_map<std::string, int> map;

    map[end] = 0;
    queue.push(end);

    while (!queue.empty()) {
        std::string top = queue.front();
        queue.pop();

        std::string left = rotate_left(top);
        if (!map.count(left)) {
            map[left] = map[top] + 1;
            if (left == start) return map[left];
            queue.push(left);
        }

        std::string right = rotate_right(top);
        if (!map.count(right)) {
            map[right] = map[top] + 1;
            if (right == start) return map[right];
            queue.push(right);
        }
    }

    return -1;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        end.clear();
        for (int i = 0; i < 10; ++i) {
            char c;
            std::cin >> c;
            end.push_back(c);
        }
        std::cout << bfs() << "\n";
    }
}
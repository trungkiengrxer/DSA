/*
Cho N công việc. Mỗi công việc được biểu diễn như một bộ 3 số nguyên dương <JobId, Deadline, Profit>, trong đó JobId là mã của việc, Deadline là thời gian kết thúc của việc, Profit là lợi nhuận đem lại nếu hoàn thành việc đó đúng hoặc trước thời gian. Thời gian tối thiểu để hoàn thành mỗi công việc là 1 đơn vị thời gian. Hãy cho biết lợi nhuận lớn nhất có thể thực hiện các việc với giả thiết mỗi việc được thực hiện đơn lẻ.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất là số lượng Job N; phần thứ hai đưa vào 3×N số tương ứng với N job.
T, N, JobId, Deadline, Profit thỏa mãn ràng buộc:1≤T≤100;  1≤N≤1000; 1≤ JobId ≤1000; 1≤ Deadline ≤1000; 1≤ Profit ≤1000.

Output:
Đưa số lượng công việc tương ứng và lợi nhuận lớn nhất có thể đạt được.
*/

#include <algorithm>
#include <iostream>
#include <vector>

bool comparator(std::pair<int, int> a, std::pair<int, int> &b) { return a.second > b.second; }

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, count = 0, result = 0;
        std::cin >> n;

        std::vector<bool> used(1001, false);
        std::vector<std::pair<int, int>> job_id(n);

        for (int i = 0; i < n; ++i) {
            int id;
            std::cin >> id >> job_id[i].first >> job_id[i].second;
        }

        std::sort(job_id.begin(), job_id.end(), comparator);

        for (int i = 0; i < n; ++i) {
            for (int j = job_id[i].first; j >= 1; --j) {
                if (used[j]) continue;

                used[j] = true;
                ++count;
                result += job_id[i].second;
                break;
            }
        }

        std::cout << count << " " << result << "\n";
    }
}
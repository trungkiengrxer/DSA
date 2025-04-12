#include <iostream>
#include <list>

int main() {
    std::list<int> list(2, 100);
    list.push_front(200);
    list.push_front(300);
    for (auto num : list) std::cout << num << "\n";
}
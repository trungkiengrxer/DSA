#include <iostream>
#include <vector>
#include <unordered_set>

struct ListNode {
    int data;
    ListNode *next;
};

typedef ListNode* Node;

void travel(Node head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
}

void add_back(Node &head, Node &tail, int value, std::unordered_set<int> &set) {
    if (set.find(value) != set.end()) return;
    set.insert(value);

    Node new_node = new ListNode;
    new_node->data = value;
    new_node->next = nullptr;

    if (head == nullptr) {
        head = new_node;
        tail = new_node;
        return;
    }

    tail->next = new_node;
    tail = new_node;
}

int main() {
    int n;
    std::cin >> n;
    Node head = nullptr, tail = nullptr;
    std::unordered_set<int> set;

    while (n--) {
        int value;
        std::cin >> value;
        add_back(head, tail, value, set);
    }

    travel(head);
}
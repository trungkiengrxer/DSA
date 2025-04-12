#include <iostream>
#include <vector>

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

void add_back(Node &head, int value) {
    Node new_node = new ListNode;
    new_node->data = value;
    new_node->next = nullptr;

    if (head == nullptr) {
        head = new_node;
        return;
    }

    Node temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void delete_node(Node &head, int value) {
    if (head == nullptr) return;
    while (head != nullptr && head->data == value) {
        Node temp = head;
        head = head->next;
        delete temp;
    }

    Node current = head;
    while (current != nullptr && current->next != nullptr) {
        if (current->next->data == value) {
            Node temp = current->next;
            current->next = current->next->next;
            delete temp;
            continue;
        }
        current = current->next;
    }
}

int main() {
    int n;
    std::cin >> n;

    Node head = nullptr;

    while (n--) {
        int value;
        std::cin >> value;
        add_back(head, value);
    }

    int x;
    std::cin >> x;

    delete_node(head, x);

    travel(head);
}
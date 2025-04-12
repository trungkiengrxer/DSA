#include <iostream>
#include <string>

using namespace std;

struct LinkedList {
    struct Node {
        string data;
        Node *next;
        Node() {}
        Node(string _data) {
            data = _data;
            next = nullptr;
        }
    };

    Node *head = nullptr;

    void addFirst(string v) {
        Node *new_node = new Node();
        new_node->data = v;
        new_node->next = head;
        head = new_node;
    }

    void printList() {
        for (Node *p = head; p != NULL; p = p->next) {
            cout << p->data << " ";
        }
        cout << endl;
    }

    void addLast(string v) {
        Node *new_node = new Node(v);
        if (head == NULL) {
            head = new_node;
            return;
        }
        Node *p = head;
        while (p->next != NULL) p = p->next;
        p->next = new_node;
    }

    void insertAfter(string pivot, string newKey) {
        Node *p = head;
        while (p != nullptr && p->data != pivot) {
            p = p->next;
        }
        Node *new_node = new Node(newKey);
        new_node->next = p->next;
        p->next = new_node;
    }

    void removeFirst() {
        if (head->next == nullptr) return;
        Node *p = head;
        head = head->next;
        delete (p);
    }

    void removeLast() {
        Node *p = head;
        while (p->next->next != NULL) p = p->next;
        Node *temp = p->next;
        p->next = nullptr;
        delete (temp);
    }

    bool searchByKey(string key) {
        Node *p = head;
        while (p != nullptr) {
            if (p->data == key) return true;
            p = p->next;
        }
        return false;
    }

    void removeByKey(string key) {
        if (head == nullptr) return; 
        if (head->data == key) {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node *p = head;
        while (p->next != nullptr && p->next->data != key) {
            p = p->next;
        }
        if (p->next == nullptr) return; 
        Node *temp = p->next;
        p->next = p->next->next;
        delete temp;
    }
};

struct Stack {
    LinkedList list;
    Stack() {
        list;
    }

    void push(string value) {
        list.addFirst(value);
    }

    void pop() {
        list.removeFirst();
    }

    string top() {
        return list.head->data;
    }
};

int main() {
    Stack stack;
    stack.push("3");
    stack.push("5");
    stack.push("7");
    std::cout << stack.top() << "\n";
    stack.pop();
    std::cout << stack.top() << "\n";
    stack.pop();
    std::cout << stack.top();
}
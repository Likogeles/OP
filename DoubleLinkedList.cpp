#include <iostream>
using namespace std;

struct Student {
    string name;
    string surname;

    Student() {
        name = "1";
        surname = "2";
    }

    Student(string n, string s) {
        name = n;
        surname = s;
    }

    bool operator< (Student& a) {
        return toString() < a.toString();
    }

    bool operator> (Student& a) {
        return toString() > a.toString();
    }

    bool operator >= (Student& a) {
        return toString() >= a.toString();
    }

    bool operator <= (Student& a) {
        return toString() <= a.toString();
    }

    string toString() {
        return surname + " " + name;
    }
};

struct Node
{
    Student value;
    Node* next;
    Node* prev;

    Node(Student v, Node* p, Node* n) {
        value = v;
        next = n;
        prev = p;
    }
};

struct DoubleLinkedList {
    Node* head, * tail;
    int size;

    DoubleLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    ~DoubleLinkedList() {
        while (size != 0)
            popFront();
    }

    Node* getNode(int index) {
        Node* n = head;
        for (int i = 0; i < index; i++)
            n = n->next;
        return n;
    }

    Student& operator [] (int index) {
        return getNode(index)->value;
    }

    void push(Student new_value) {
        if (head == nullptr) {
            pushFront(new_value);
            return;
        }
        if (head->value >= new_value) {
            pushFront(new_value);
            return;
        }
        if (tail->value <= new_value) {
            pushBack(new_value);
            return;
        }
        for (Node* n = head; n; n = n->next)
        {
            Node* nextNode = n->next;
            if (nextNode == nullptr) {
                pushBack(new_value);
                return;
            }
            if (n->value < new_value && new_value <= nextNode->value) {
                insertAfter(n, new_value);
                return;
            }
        }
    }

    void insertAfter(Node* elem, Student value) {
        Node* newNode = new Node(value, elem, elem->next);
        elem->next->prev = newNode;
        elem->next = newNode;
        size++;
        if (tail == elem)
            tail = tail->next;
    }

    void pushFront(Student value) {
        Node* next = head;
        head = new Node(value, nullptr, head);
        if (tail == nullptr)
            tail = head;
        if (next)
            next->prev = head;
        size++;
    }

    void pushBack(Student value) {
        Node* prev = tail;
        tail = new Node(value, tail, nullptr);
        if (head == nullptr)
            head = tail;
        if (prev)
            prev->next = tail;
        size++;
    }

    void popFront() {
        Node* popNode = head;
        if (popNode) {
            head = head->next;
            if (head)
                head->prev = nullptr;
            delete popNode;
            if (head == nullptr)
                tail = nullptr;
            size--;
        }
    }

    void popBack() {
        Node* popNode = tail;
        if (popNode) {
            tail = tail->prev;
            if (tail)
                tail->next = nullptr;
            delete popNode;
            if (tail == nullptr)
                head = nullptr;
            size--;
        }
    }

    void print() {
        cout << "Список студентов:\n";
        for (Node* n = head; n; n = n->next)
        {
            cout << n->value.toString() << "\n";
        }
        cout << "\n\n";
    }
};

#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node* next;

    Node(int v, Node* n) {
        value = v;
        next = n;
    }
};

struct LinkedList {
    Node* head, * tail;
    int size;

    LinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    ~LinkedList() {
        while (size != 0)
            popFront();
    }

    Node* getNode(int index) {
        Node* n = head;
        for (int i = 0; i < index; i++)
            n = n->next;
        return n;
    }

    int& operator [] (int index) {
        return getNode(index)->value;
    }

    void pushFront(int value) {
        head = new Node(value, head);
        if (tail == nullptr)
            tail = head;
        size++;
    }

    void popFront() {
        Node* next_head = head->next;
        delete head;
        head = next_head;
        if (head == nullptr)
            tail = nullptr;
        size--;
    }

    void pushBack(int value) {
        if (size == 0) {
            pushFront(value);
        }
        else {
            insertAfter(tail, value);
        }
    }

    void insertAfter(Node* elem, int value) {
        elem->next = new Node(value, elem->next);
        size++;
        if (tail == elem)
            tail = tail->next;
    }

    void eraseAfter(Node* elem) {
        Node* nextElem = elem->next;
        elem->next = nextElem->next;
        if (tail == nextElem)
            tail = elem;
        delete nextElem;
        size--;
    }

    void print() {
        for (Node* n = head; n; n = n->next)
            cout << n->value << " ";
        cout << "\n";
    }
};

/*
int main()
{
    LinkedList LL;

    LL.pushFront(3);
    LL.pushFront(5);
    LL.pushFront(4);
    LL.print();

    LL.insertAfter(LL.getNode(1), 100);
    LL.print();

    LL.eraseAfter(LL.getNode(1));
    LL.print();

    LL.pushBack(4);
    LL.print();
}
*/

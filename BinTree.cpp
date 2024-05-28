#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node* big;
    Node* small;

    Node(int val)
    {
        value = val;
        big = nullptr;
        small = nullptr;
    }
};

struct BinTree
{
    Node* root = nullptr;

    void addValue(int v) {
        Node* newNode = new Node(v);
        if (root == nullptr) {
            root = newNode;
            return;
        }

        bool flag = true;
        Node* nowNode = root;
        while (flag) {
            if (nowNode->value < newNode->value) {
                if (nowNode->big) {
                    nowNode = nowNode->big;
                }
                else {
                    nowNode->big = newNode;
                    flag = false;
                }
            }
            else {
                if (nowNode->small) {
                    nowNode = nowNode->small;
                }
                else {
                    nowNode->small = newNode;
                    flag = false;
                }
            }
        }
    }

    void removeValue(int v) {
        removeValueUtil(root, v);
    }

    Node* removeValueUtil(Node* n, int v) {
        if (!n) {
            return n;
        }
        if (n->value > v) {
            n->small = removeValueUtil(n->small, v);
        }
        else if (n->value < v) {
            n->big = removeValueUtil(n->big, v);
        }
        else {
            if (!n->small) {
                Node* tmp_n = n->big;
                delete n;
                return tmp_n;
            }
            else if (!n->big) {
                Node* tmp_n = n->small;
                delete n;
                return tmp_n;
            }
            Node* tmp_n = minValue(n->big);
            n->value = tmp_n->value;
            n->big = removeValueUtil(n->big, tmp_n->value);
        }
        return n;
    }

    Node* minValue(Node* n) {
        if (!n->small) {
            return n;
        }
        return minValue(n->small);
    }

    void print() {
        printNode(root, "");
    }

    void printNode(Node* n, string add_str) {
        cout << add_str << n->value << endl;
        if (n->small) {
            printNode(n->small, add_str + "-");
        }
        if (n->big) {
            printNode(n->big, add_str + "-");
        }
    }
};

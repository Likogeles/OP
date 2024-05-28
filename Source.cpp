#include <iostream>
#include <Vector>
using namespace std;


struct Item {
    string key = "";
    int value;
};


struct HashTable {
    Item* elements;
    int capacity = 32;
    int count = 0;

    long hash(string key) {
        long sum = 0;
        for (int i = 0; i < key.length(); i++) {
            sum += key[i] + i + 1;
        }
        return sum % capacity;
    }

    void init() {
        elements = (Item*)malloc(capacity * sizeof(Item));
    }
    void clean() {
        free(elements);
    }

    void my_realloc() {
        if (count >= capacity - 3) {
            elements = (Item*)realloc(NULL, capacity * 2);
            capacity *= 2;
        }
    }

    void add(string key, int value) {
        my_realloc();
        long hashed = hash(key);
        if (elements[hashed].key != "") {
            long temp = hashed + 1;
            while (elements[temp].key != "") {
                temp++;
            }
            elements[temp].key = key;
            elements[temp].value = value;
        }
        else {
            elements[hashed].key = key;
            elements[hashed].value = value;
        }
        count++;
    }
    
    int get(string key) {
        long hashed = hash(key);
        if (elements[hashed].key == key) {
            return elements[hashed].value;
        }
        else {
            for (long i = hashed + 1; i < hashed + capacity; i++) {
                if (i == hashed)
                    break;
                if (elements[i].key == key)
                    return elements[hashed].value;
            }
            return -1;
        }
    }
};


int main()
{
    setlocale(LC_ALL, "");

    HashTable HT;

    HT.init();
    HT.add("bad", 13);
    HT.add("good", 7);
    HT.add("just", 4);
    HT.add("tsuj", 8);

    cout << HT.get("bad") << endl;
    cout << HT.get("good") << endl;
    cout << HT.get("just") << endl;
    cout << HT.get("tsuj") << endl;

    HT.clean();
    /*
    vector<int> vv = {15, 9, 7, 33, 10, 25};

    vv = quickSort(vv);

    for (int i : vv) {
        cout << i << " ";
    }
    */
    /*
    BinTree BT;

    BT.addValue(3);
    BT.addValue(4);
    BT.addValue(5);
    BT.addValue(4);
    BT.addValue(1);
    BT.addValue(2);
    BT.addValue(0);
    BT.addValue(7);
    BT.addValue(6);
    BT.addValue(8);

    BT.print();

    BT.removeValue(3);
    BT.addValue(3);


    BT.print();
    */
    /*
    DoubleLinkedList DLL;

    DLL.push(Student("Иван", "Иванов"));
    DLL.push(Student("Сергей", "Петров"));

    DLL.print();

    DLL.push(Student("Кирилл", "Долгов"));
    DLL.push(Student("Илья", "Абрамов"));

    DLL.print();

    
    DLL.push(Student("Ян", "Янов"));
    DLL.push(Student("Иван", "Иванов"));
    
    DLL.print();
    */
    /*
    DLL.pushFront(3);
    DLL.pushFront(2);
    DLL.pushFront(1);
    DLL.print();

    DLL.pushBack(4);
    DLL.print();

    DLL.popFront();
    DLL.print();

    DLL.popBack();
    DLL.print();
    */

}

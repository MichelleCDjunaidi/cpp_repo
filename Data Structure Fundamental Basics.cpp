#include <iostream>
using namespace std;

struct Student {
    string name;
    int age;
};

struct node {
    int val;

    node* nxt, * prv;

    node(int _val) {
        val = _val;
        nxt = NULL;
        prv = NULL;
    }
};

struct LinkedList {
    node* head, * tail;

    LinkedList() {
        head = tail = NULL;
    }

    void push_back(int val) {
        if (head == NULL) {
            head = tail = new node(val);
            return;
        }

        tail->nxt = new node(val);
        tail->nxt->prv = tail;
        tail = tail->nxt;
    }

    void push_front(int val) {
        if (head == NULL) {
            head = tail = new node(val);
            return;
        }

        head->prv = new node(val);
        head->prv->nxt = head; //draw a nxt arrow to head dari tempat head->prv
        head = head->prv;
    }

    void pop_back() {
        if (head == tail) {
            delete(tail);
            head = tail = NULL;
            return;
        }

        tail = tail->prv;
        delete(tail->nxt);
        tail->nxt = NULL;
    }

    void pop_front() {
        if (head == tail) {
            // head = 101
            // head dan tail itu hanya menyimpan alamat, tapi gak nyimpen isi dari alamatnya
            delete(head);
            head = tail = NULL;
            return;
        }

        head = head->nxt; //balik lagi pindah rumah
        delete(head->prv);
        head->prv = NULL; //hapus panah
    }

    // t.p t   t.n
    // 10  13  5
    void erase(node* target) {
        if (target == head) {
            pop_front();
            return;
        }
        if (target == tail) {
            pop_back();
            return;
        }
        target->prv->nxt = target->nxt; //dari tempat target->prv, draw a nxt arrow to tempat target->nxt
        target->nxt->prv = target->prv;
        delete(target);
    }
};


void linked_list() {
    LinkedList test;
    // 987 10 123
    test.push_back(10);
    test.push_back(5);
    test.pop_back();
    test.push_back(123);
    test.push_front(987);
    test.erase(test.head->nxt);
    test.erase(test.tail);

    for (node* it = test.head; it != NULL; it = it->nxt) {
        cout << it->val << " ";
    }
    cout << endl;
}

int main() {

    linked_list();

    Student c;
    c.name = "Michelle";
    c.age = 17;
    cout << c.name << " " << c.age << endl;

    int a = 5;
    int* b = &a;
    cout << "Initial memory " << b << endl;
    // b -> alamat
    // *b -> isi dari memori di b 
    *b = 10;

    cout << a << " " << b << endl;
}

/*
#include <iostream>
#include <list>
#include <queue>
#include <stack>
using namespace std;

struct Student {
  string name;
  int age;
};

struct node {
  int val;

  node *nxt, *prv;

  node(int _val) {
    val = _val;
    nxt = NULL;
    prv = NULL;
  }
};

struct LinkedList {
  node *head, *tail;

  LinkedList() {
    head = tail = NULL;
  }

  void push_back(int val){
    if(head == NULL) {
      head = tail = new node(val);
      return;
    }

    tail->nxt = new node(val);
    tail->nxt->prv = tail;
    tail = tail->nxt;
  }

  void push_front(int val){
    if(head == NULL) {
      head = tail = new node(val);
      return;
    }

    head->prv = new node(val);
    head->prv->nxt = head; //draw a nxt arrow to head dari tempat head->prv
    head = head->prv;
  }

  void pop_back(){
    if (head == tail) {
      delete(tail); //hapus inhabitant dari rumah
      head = tail = NULL; //ganti nama jalan sehingga no longer points at the house before it
      return;
    }

    tail = tail->prv;
    delete(tail->nxt);
    tail->nxt = NULL;
  }

  void pop_front() {
    if (head==tail) {
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
  void erase(node* target){
    if(target == head){
      pop_front();
      return;
    }
    if(target == tail){
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

  for(node* it = test.head; it != NULL; it = it->nxt) {
    cout << it->val << " ";
  }
  cout << endl;
}

void try_stack() {
  stack<int> stk;

  stk.push(10);
  stk.push(13);
  stk.pop();
  cout << stk.top() << endl;
}

void try_queue() {
  queue<int> q;
  q.push(5);
  q.push(13);
  q.push(19);
  cout << q.front() << endl;
  q.pop();
  cout << q.front() << endl;
}

int main() {
  // try_stack();
  try_queue();
  // linked_list();

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
*/

#include <iostream>
using namespace std;

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
        head = tail = NULL; //set keduanya untuk ngerefer ke NULL
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
            delete(tail); //hapus inhabitant dari rumah
            head = tail = NULL; //ganti nama jalan sehingga no longer points at the house before it
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
};

int main() {
    int N, val;
    string command;

    LinkedList test;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> command;
        if (command == "push_back") {
            cin >> val;
            test.push_back(val);
        }
        else if (command == "push_front") {
            cin >> val;
            test.push_front(val);
        }
        else if (command == "pop_front") test.pop_front();
        else test.pop_back();
    }

    for (node* it = test.head; it != NULL; it = it->nxt) {
        cout << it->val << endl;
    }
}

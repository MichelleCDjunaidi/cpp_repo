#include <iostream>
#include <algorithm>
using namespace std;

int N;
long long B;
int arr[20005];

struct fraction {
    int x, y;

    // Constructor dari struct fraction
    fraction() {
        cout << "test" << endl;
    }

    fraction(int _x, int _y) {
        cout << "called" << endl;
        x = _x;
        y = _y;
    }
    // Represent (x / y)
};

// Array, a -> indeks yang lebih kecil, b -> indeks yang lebih gede
bool cmp(fraction a, fraction b) {
    long long lft = a.x * b.y;
    long long rgt = a.y * b.x;
    return lft < rgt;
}

bool cmp2(int a, int b) {
    return a > b;
}

int hitung() {
    long long total = 0, hasil = 0;
    sort(arr, arr + N, cmp2);
    // reverse(arr,arr+N);
    for (int j = 0; j < N; j++) {
        if (total >= B) {
            hasil = j;
            break;
        }
        else total += arr[j];
    }

    return hasil;
}

int main() {
    // fraction abc(3, 5);
    // abc = {3, 5};
    // cout << abc.x << " " << abc.y << endl;

    cin >> N >> B;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    cout << hitung();
    return 0;
}
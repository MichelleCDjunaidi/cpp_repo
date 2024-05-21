#include <iostream>
#include <algorithm>
using namespace std;

int N;
long long B;
long long total, hasil;
int arr[20005];

void hitung() {
    total = 0;
    sort(arr, arr + N);
    reverse(arr, arr + N);
    for (int j = 0; j < N; j++) {
        if (total >= B) {
            hasil = j;
            return;
        }
        else total += arr[j];
    }
}

int main() {
    cin >> N >> B;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    hitung();
    cout << hasil;
    return 0;
}

#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll M = 1e5 + 5;
int N, C;
int ar[M];
int t;

bool can(int jarak) {
    int last = 0;
    int cnt = 1;
    for (int k = 1; k < N; k++) {
        if (ar[k] - ar[last] >= jarak) { // Bisa taro sapi baru di indeks K
            last = k;
            cnt += 1;
        }
    }
    return cnt >= C;
}

void distance() {
    ll possibleanswer;
    ll l = 0, r = 1e9 + 5;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (can(mid)) {
            possibleanswer = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    cout << possibleanswer << endl;
}

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> N >> C;
        for (int j = 0; j < N; j++) {
            cin >> ar[j];
        }
        sort(ar, ar + N);
        distance();
    }
}
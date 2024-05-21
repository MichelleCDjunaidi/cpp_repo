#include <iostream>
#include <iomanip>
using namespace std;

const int N = 1e5 + 5;

long long n;
long long p;
long long ar[N];
long long store[N];
long long sum;

bool can(double waktu) {
    double power;
    power = 0;
    for (int i = 1; i < n + 1; i++) {
        if (waktu * ar[i] - store[i] >= 0) {
            power += waktu * ar[i] - store[i];
        }
    }
    if (waktu * p > power) {
        return true;
    }
    return false;
}

void time() {
    for (int i = 1; i < n + 1; i++) {
        sum += ar[i];
    }

    if (p >= sum) {
        cout << -1 << endl;
        return;
    }

    double l = 0, r = 1e18;

    for (int i = 0; i < 100; i++) {
        double mid = (l + r) / 2;
        if (can(mid))l = mid;
        else r = mid;
    }

    cout << r << endl;
}

int main() {
    cout << fixed << setprecision(6);
    cin >> n >> p;
    for (int i = 1; i < n + 1; i++) {
        cin >> ar[i] >> store[i];
    }
    time();
}
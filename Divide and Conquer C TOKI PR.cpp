#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll A, B, C, N;
ll MOD;

ll mulmod(ll a, ll b) {
    return (a * b) % MOD;
}

ll hasil(ll base, ll pangkat) {
    ll angka;

    if (pangkat == 0) return 1;
    if (pangkat == 1) return base;

    angka = hasil(base, pangkat / 2);

    if (pangkat % 2 == 1) angka = mulmod(mulmod(angka, angka), base);
    if (pangkat % 2 == 0) angka = mulmod(angka, angka);

    return angka;
}

int main() {
    cin >> A >> B >> C >> N;
    MOD = N;
    ll jawab = hasil(A, B);
    for (int i = 1; i < C; i++) {
        jawab = hasil(jawab, B);
    }
    cout << jawab + 1;
}
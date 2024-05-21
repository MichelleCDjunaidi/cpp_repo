#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e6;

typedef long long ll;

ll A, B;
bool isBiggerThanMod = false;

ll mulmod(ll a, ll b) {
    if (a * b >= MOD)isBiggerThanMod = true;
    return (a * b) % MOD;
}

ll pangkat(ll x, ll y) {
    ll angka;
    if (y == 0) return 1;

    angka = pangkat(x, y / 2) % MOD; // 1e6 * 1e6
    if (y % 2 == 1) angka = mulmod(mulmod(angka, angka), x);
    if (y % 2 == 0) angka = mulmod(angka, angka);

    return angka;
}

int main() {
    cin >> A >> B;
    ll ans = pangkat(A, B);
    if (isBiggerThanMod) {
        printf("%06lld\n", ans);
    }
    else cout << ans;
}
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

const int MOD = 1e9 + 8;

// a^b mod c
ll fast_exponent(ll a, ll b) {
    if (b == 0)return 1;
    ll tmp = fast_exponent(a, b / 2);
    tmp = (tmp * tmp) % MOD;

    if (b % 2 == 1)tmp = (tmp * a) % MOD;
    return tmp;
}

ll fast_iterative(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b % 2 == 1)res = res * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return res;
}

// a * b mod c

// FYI -> long long ~ 8 * 10 ^ 18
// constraint a, b, c <= 10^18

// a = 10^15, b = 10^15, c = (10^18 - 1) ?

// Russian Peasant

// int main() {
// 	cout << fast_exponent(2,100) << endl;
//   cout << fast_iterative(2, 100) << endl;
//   cout << russian_peasant(1e15, 1e15, (ll)1e18 + 1) << endl;
//   cout << fast_russian_peasant(1e15, 1e15, (ll)1e18 + 1) << endl;

// }

const int K = 1000;

ll fast_russian_peasant(ll a, ll b, ll mod) {
    if (b == 0)return 0;
    ll tmp = fast_russian_peasant(a, b / K, mod);
    tmp = (tmp * K) % mod;

    if (b % K > 0)tmp = tmp + (a * (b % K)) % mod;
    return tmp;
}

ll fpb(ll a, ll b) {
    if (b == 0)return a;
    return fpb(b, a % b);
}

const int MAXN = 200;

ll memo[MAXN][MAXN];
ll array_p[MAXN], array_q[MAXN], array_r[MAXN];

ll super_trombo(ll idx, ll idy, ll z) {
    if (z == 0)return array_p[idx] + array_q[idy];

    if (memo[idx][idy] != -1)return memo[idx][idy];

    // let a = (x ^ 2 mod (x + y)) + y
    ll a = fast_russian_peasant(array_p[idx], array_p[idx], array_p[idx] + array_q[idy]) + array_q[idy];
    ll b = array_p[idx] + array_q[idy];
    // let b = (x + y)
    // fpb(a, b) ? -> euclid 
    return memo[idx][idy] = fpb(a, b);
}

int main() {
    int T, N;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        memset(memo, -1, sizeof memo);

        ll total = 0;
        for (int j = 0; j < N; j++) {
            cin >> array_p[j] >> array_q[j] >> array_r[j];
        }

        for (int c = 0; c < N; c++) {
            for (int d = 0; d < N; d++) {
                for (int e = 0; e < N; e++) {
                    total += super_trombo(c, d, array_r[e]);
                }
            }
        }
        cout << "Kasus #" << i + 1 << ": " << total << endl;
    }
}

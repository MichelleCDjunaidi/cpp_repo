#include <iostream>
using namespace std;

typedef long long ll;

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

const int K = 8;

ll fast(ll a, ll b, ll mod) {
    if (b == 0)return 0;
    ll tmp = fast(a, b / K, mod);
    tmp = (tmp * K) % mod;

    if (b % K > 0)tmp = tmp + (a * (b % K)) % mod;
    return tmp;
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
//   cout << fast(1e15, 1e15, (ll)1e18 + 1) << endl;

// }

ll russian_peasant(ll a, ll b, ll mod) {
    ll res = 0;
    while (b > 0) {
        if (b % 2 == 1)res = (res + a) % mod;
        a = (a + a) % mod;
        b /= 2;
    }
    return res;
}

ll fpb(ll a, ll b) {
    if (b == 0)return a;
    return fpb(b, a % b);
}

ll super_trombo(ll x, ll y, ll z) {
    if (z == 0)return x + y;

    // let a = (x ^ 2 mod (x + y)) + y
    ll a = russian_peasant(x, x, x + y) + y;
    ll b = x + y;
    // let b = (x + y)
    // fpb(a, b) ? -> euclid 
    return fpb(a, b);
}

int main() {
    int T, N;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;

        ll total = 0;
        ll array_p[N], array_q[N], array_r[N];

        for (int j = 0; j < N; j++) {
            cin >> array_p[j] >> array_q[j] >> array_r[j];
        }
        for (int c = 0; c < N; c++) {
            for (int d = 0; d < N; d++) {
                for (int e = 0; e < N; e++) {
                    total += super_trombo(array_p[c], array_q[d], array_r[e]);
                }
            }
        }
        cout << "Kasus #" << i + 1 << ": " << total << endl;
    }
}

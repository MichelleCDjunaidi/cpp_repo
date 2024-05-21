#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll K = 1e6 + 5;

ll arr[K];
ll jawaban[K];
ll kelompok = 1;

ll banyakparsel(ll tengah, ll kel) {
    ll total = 0;
    for (ll j = 0; j < kel; j += 1) {
        total += ll(tengah / arr[j]);
    }
    return total;
}

ll cari(ll x) {
    ll L = 0;
    ll R = 4e18;
    ll ans_lower = 0;
    ll ans_upper = -1;

    while (L <= R) {
        ll mid = (L + R) / 2;
        ll hasil = banyakparsel(mid, kelompok);
        if (hasil > x) {
            R = mid - 1;
        }
        if (hasil < x) {
            L = mid + 1;
        }
        if (hasil == x) {
            ans_lower = mid;
            R = mid - 1;
        }
    }

    L = 0;
    R = 4e18;

    while (L <= R) {
        ll mid = (L + R) / 2;
        ll hasil = banyakparsel(mid, kelompok);
        //cout<< "Before" << L << " " << R <<" " << mid << endl;
        if (hasil > x) {
            R = mid - 1;
        }
        if (hasil < x) {
            L = mid + 1;
        }
        if (hasil == x) {
            ans_upper = mid;
            L = mid + 1;
        }
        //cout<< "After" << L << " " << R <<" " << mid << endl;
    }
    return ans_upper - ans_lower + 1;
}

int main() {
    ll parsel;
    cin >> kelompok >> parsel;
    for (ll i = 0; i < kelompok; i += 1) {
        cin >> arr[i];
    }
    cout << cari(parsel);
}
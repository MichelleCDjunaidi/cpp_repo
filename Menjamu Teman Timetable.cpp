#include <iostream>
#include <utility>
#include <algorithm>

#define fi first
#define se second

using namespace std;

int guest;
pair<int, pair<int, int>> teman[100005];

bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
    return a.se.se < b.se.se;
}

int rencana() {
    sort(teman, teman + guest, cmp);
    int total = 1;
    int a = 0;
    for (int i = 1; i < guest; i++) {
        if (teman[i].fi < teman[a].se.se) continue;
        a = i;
        total += 1;
    }
    return total;
}

int main() {
    cin >> guest;
    for (int i = 0; i < guest; i++) {
        cin >> teman[i].fi >> teman[i].se.fi;
        teman[i].se.se = teman[i].fi + teman[i].se.fi;
    }
    cout << rencana();
}
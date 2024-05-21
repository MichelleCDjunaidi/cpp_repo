#include<bits/stdc++.h>
using namespace std;

const int N = 15;

int n, a, b;
int ans[N];
bool used[N];

void backtrack(int idx) {
    if (idx > n) {
        for (int i = 2; i < n; i++) {
            if (ans[i] > ans[i - 1] && ans[i] > ans[i + 1])continue;
            if (ans[i] < ans[i - 1] && ans[i] < ans[i + 1])continue;
            else return;
        }

        for (int i = 1; i <= n; i++) {
            cout << ans[i];
        }
        cout << endl;
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (used[i])continue;

        ans[idx] = i;
        used[i] = true;
        backtrack(idx + 1);
        used[i] = false;
    }

}

int main() {
    cin >> n;

    backtrack(1);
}
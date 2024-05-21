#include <bits/stdc++.h>
using namespace std;

const int INF = 60000;

int N;
int sisa_uang;
int jenis[500];
int dp[50000];

//state = cek sisa uang yang dipunyai, cek apakah ada kombinasi uang yang memenuhi

int knapsack(int sisa_uang) {
    if (sisa_uang < 0)return INF;
    if (sisa_uang == 0) return 0;
    if (dp[sisa_uang] != INF)return dp[sisa_uang];
    int best = INF;
    for (int i = 0; i < N; i++) {
        best = min(best, knapsack(sisa_uang - jenis[i]) + 1);
    }

    return dp[sisa_uang] = best;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for (int j = 0; j < 50000; j++) {
        dp[j] = INF;
    }
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> jenis[i];
    }
    cin >> sisa_uang;
    cout << knapsack(sisa_uang);
}
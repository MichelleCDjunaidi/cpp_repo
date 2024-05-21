#include <bits/stdc++.h>
using namespace std;

const int INF = 60000;

typedef unsigned short ushort;

int N;
int sisa_uang;
int jenis[500];
ushort dp[500][50001];

//state = cek sisa uang yang dipunyai, cek apakah ada kombinasi uang yang memenuhi

ushort knapsack(int idx, int sisa_uang) {
    if (idx < 0 || sisa_uang < 0)return INF;
    if (sisa_uang == 0) return 0;
    if (dp[idx][sisa_uang] != INF)return dp[idx][sisa_uang];

    ushort best1 = min(knapsack(idx - 1, sisa_uang), (ushort)(knapsack(idx - 1, sisa_uang - jenis[idx]) + 1));
    ushort best2 = min(best1, (ushort)(knapsack(idx, sisa_uang - jenis[idx]) + 1));

    return dp[idx][sisa_uang] = best2;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for (int i = 0; i < 500; i++) {
        for (int j = 0; j < 50000; j++) {
            dp[i][j] = INF;
        }
    }
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> jenis[i];
    }
    cin >> sisa_uang;
    cout << knapsack(N - 1, sisa_uang);
}
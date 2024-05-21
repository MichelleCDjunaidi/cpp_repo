#include <bits/stdc++.h>
using namespace std;

const int INF = 60000;

int N;
int sisa_uang;
int jenis[500];
int dp[50001];

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

/*const int N = 2000;
const int M = 5000;

int V[N], W[N];

int dp2[N+1][M+1];
int knapsack(int idx, int sisa_berat){
  if(sisa_berat < 0)return -INF; // invalid
  if(idx == 0 || sisa_berat == 0)return 0; // valid
  if(dp2[idx][sisa_berat] != -1)return dp2[idx][sisa_berat];

  int best = max(knapsack(idx - 1, sisa_berat),
                knapsack(idx - 1, sisa_berat - W[idx]) + V[idx]);

  return dp2[idx][sisa_berat] = best;
}

int dp[N];

int fibo(int x){
  if(x <= 1)return 1;
  if(dp[x] != -1)return dp[x];
  return dp[x] = fibo(x - 1) + fibo(x - 2);
}

int fibo2(int x){
  int a = 1, b = 1;
  for(int i = 2; i <= x; i++){
    int c = a + b;
    a = b, b = c;
  }
  return b;
}

int main() {
  memset(dp, -1, sizeof dp);
  fibo(50);
  // fibo2(50);
    // int n, m; cin >> n >> m;
  // for(int i = 1; i <= n; i++){
  //   cin >> W[i] >> V[i];
  // }

  // cout << knapsack(n, m);
}
*/

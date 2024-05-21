#include <bits/stdc++.h>
using namespace std;

int V, H, N;
int v1[512], h1[512], v2[512], h2[512];
int meps[512][512];
long long dp[505][505];

bool inRange(int y, int x) {
    return y > 0 && x > 0 && y <= V && x <= H;
}

long long tetes(int y, int x) {
    if (!inRange(y, x)) return 0;

    if (dp[y][x] != -1) return dp[y][x];

    if (meps[y][x] == 0) return dp[y][x] = tetes(y + 1, x); //turun

    long long tetes1 = 0, tetes2 = 0;
    // x = H, i = x + 1 -> H + 1
    for (int i = x + 1; i < H + 1; i++) {//kanan
        if (meps[y][i] == 0) {
            tetes1 = tetes(y, i);
            break;
        }
    }
    for (int j = x - 1; j > -1; j--) {//kiri
        if (meps[y][j] == 0) {
            tetes2 = tetes(y, j);
            break;
        }
    }
    return dp[y][x] = tetes1 + tetes2 + 1;
}

int main() {
    memset(dp, -1, sizeof dp);
    cin >> V >> H >> N;
    for (int i = 0; i < N; i++) {
        cin >> v1[i] >> h1[i] >> v2[i] >> h2[i];
        for (int j = v1[i]; j <= v2[i]; j++) {
            for (int k = h1[i]; k <= h2[i]; k++) {
                meps[j][k] = 1;
            }
        }
    }

    // for(int i = 1; i <= V; i++){
    //   for(int j = 1; j <= H; j++){
    //     cout << meps[i][j];
    //   }
    //   cout << endl;
    // }

    long long best = 0;
    for (int z = 1; z < H + 1; z++) {
        best = max(best, tetes(1, z));
    }
    cout << best;
}

/* kalau dari atas batunya
#include <bits/stdc++.h>
using namespace std;

int V, H, N;
int v1[512], h1[512], v2[512], h2[512];
int meps[512][512];
long long dp[505][505];

bool inRange(int y, int x){
  return y >= 0 && x > 0 && y <= V && x <= H;
}

long long tetes(int y, int x) {
  if (!inRange(y, x)) return 0;
  
  if (dp[y][x]!=-1) return dp[y][x];
  
  if (meps[y+1][x]==0) return dp[y][x] = tetes(y+1, x); //turun
  
  long long tetes1 = 0, tetes2 = 0;
  // x = H, i = x + 1 -> H + 1
  for (int i=x+1; i<H+1; i++){//kanan
    if (meps[y+1][i]==0) {
      tetes1 = tetes(y, i);
      break;
    }
  }
  for (int j=x-1; j>-1; j--){//kiri
    if (meps[y+1][j]==0) {
      tetes2 = tetes(y, j);
      break;
    }
  }
  return dp[y][x] = tetes1+tetes2+1;
}

int main() {
  memset(dp, -1, sizeof dp);
  cin >> V >> H >> N;
  for (int i=0; i<N; i++){
    cin >> v1[i] >> h1[i] >> v2[i] >> h2[i];
    for (int j=v1[i]; j<=v2[i]; j++){
      for (int k=h1[i]; k<=h2[i]; k++){
        meps[j][k]=1;
      }
    }
  }
  
  for(int i = 1; i <= V; i++){
    for(int j = 1; j <= H; j++){
      cout << meps[i][j];
    }
    cout << endl;
  }
  
  long long best = 0;
  for (int z=1; z<H+1; z++){
    best = max(best, tetes(0, z));
  }
  cout << best;
}
*/
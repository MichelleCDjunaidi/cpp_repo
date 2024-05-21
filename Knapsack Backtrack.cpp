#include <iostream>
#include <cstring>
using namespace std;

int dp[105][2005];
int batu[2005];
int value[2005];
int ambil[2005];
int N;
int K;
const int INF = -1E9;

int solve(int idx, int sisa_berat) {
    if (sisa_berat < 0) return INF;
    if (idx < 0 || sisa_berat == 0) return 0;
    if (dp[idx][sisa_berat] != -1) return dp[idx][sisa_berat];

    int best = max(solve(idx - 1, sisa_berat), solve(idx - 1, sisa_berat - batu[idx]) + value[idx]);

    return dp[idx][sisa_berat] = best;
}

void backtrack(int idx, int sisa_berat) {
    // Tentuin backtracknya ke mana
    if (sisa_berat < 0) return;
    if (idx < 0 || sisa_berat == 0) return;

    // idx, sisa_berat -> dapet nilai maksimumnya darimana?
    if (dp[idx][sisa_berat] == solve(idx - 1, sisa_berat)) {
        ambil[idx] = 0;
        backtrack(idx - 1, sisa_berat);
    }
    else if (dp[idx][sisa_berat] == solve(idx - 1, sisa_berat - batu[idx]) + value[idx]) {
        ambil[idx] = 1;
        backtrack(idx - 1, sisa_berat - batu[idx]);
    }
}

int main() {
    memset(dp, -1, sizeof dp);
    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        cin >> batu[i] >> value[i];
    }
    int opt = solve(K, N);
    for (int i = N - 1; i >= 0; --i) {
        if (solve(K, i) != opt) {
            backtrack(K, i + 1);
            break;
        }
    }
    for (int j = 0; j < K; j++) {
        if (ambil[j] == 1) cout << j + 1 << endl;
    }
}


#include <iostream>
#include <cstring>
using namespace std;

int N;
int dp[10000];
const int INF = -1e9;

int solve(int sisa_emas) {
	if (sisa_emas < 0) return INF;
	if (sisa_emas == 0) return 0;
	if (sisa_emas == 1) return 1;
	if (dp[sisa_emas] != -1) return dp[sisa_emas];

	int best = max((solve(sisa_emas / 2) + solve(sisa_emas / 3) + solve(sisa_emas / 4)), sisa_emas);

	return dp[sisa_emas] = best;

}

int main() {
	memset(dp, -1, sizeof dp);
	cin >> N;
	cout << solve(N);
}
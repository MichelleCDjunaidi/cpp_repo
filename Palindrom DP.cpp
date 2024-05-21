#include <iostream>
#include <cstring>
using namespace std;

int N;
const int INF = -1e6;
string pal[55];
string word;
int dp[55][55];

int solve(int idxleft, int idxright) {
    int answer;
    if (idxleft == idxright) return 1;
    if (idxleft >= idxright) return 0;
    if (dp[idxleft][idxright] != -1) return dp[idxleft][idxright];

    if (word[idxleft] == word[idxright]) {
        answer = solve(idxleft + 1, idxright - 1) + 2;
    }
    else
        //buang kiri, simpen kanan or vice versa
        answer = max(solve(idxleft + 1, idxright), solve(idxleft, idxright - 1));

    return dp[idxleft][idxright] = answer;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> pal[i];
        word = pal[i];
        memset(dp, -1, sizeof dp);
        cout << solve(0, word.length() - 1) << endl;
    }
}
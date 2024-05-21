#include <bits/stdc++.h>

using namespace std;

// you need to 1e9!!!!!! WHY
const int MOD = 1e9 + 7;

long long recursive_dice(int n, vector<long long>& dp) {
    if (n < 0) {
        return 0;
    }
    else if (n == 0 || n == 1) {
        return 1;
    }
    else if (dp[n] != -1) {
        return dp[n];
    }
    else {
        dp[n] =
        (recursive_dice(n-1, dp) + 
        recursive_dice(n-2, dp) + 
        recursive_dice(n-3, dp) + 
        recursive_dice(n-4, dp) + 
        recursive_dice(n-5, dp) + 
        recursive_dice(n-6, dp)) % MOD;
        return dp[n];
    }
}

int main() {
    int n;
    cin >> n;
    vector<long long> dp(n+1, -1);
    cout << recursive_dice(n, dp);
}


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF = 0;

ll n;
ll m;
ll d;
ll a[1e10];
ll b[1e10];
ll t[1e10];

int maximize(ll sad){
    if (sad <0) return INF;
    if (sad == 0) return 0;
    if (dp[sad] != INF)return dp[sad];
    int best = INF;
    for (int i = 0; i < N; i++) {
        best = max(best, maximize(sad + i) + b[i]-(a[i]-x));
    }

    return dp[sad] = best;
}

int main(){
    cin>>n>>m>>d;
    for (int i=0; i<m; i++){
        cin>>a[i]>>b[i]>>t[i]
    }
}
#include <bits/stdc++.h>
using namespace std;

int M, N;
int ans;

int main(){
    cin>>M>>N;
    if (M %2 == 0) ans=M*N/2;
    else if (N%2 == 0) ans=M*N/2;
    else
    ans = (M-1)*N/2+N/2;
    cout<<ans;
}
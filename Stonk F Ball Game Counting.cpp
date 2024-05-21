#include <bits/stdc++.h>
using namespace std;

int n;
int now;

int main(){
    cin>>n;
    now = 1;
    for (int i=1; i<n; i++){
        now +=i;
        now = now % n;
        if (now ==0) {now = n;}
        cout<<now<< " ";
    }
}
#include <bits/stdc++.h>
using namespace std;

int n, b;
int price[2005];

int calc(int buy, int sell){
    int leftover = b % buy;
    int dollar = b/buy;
    int newb = dollar * sell + leftover;
    return newb;
}

int maximize(){
    int base = calc(price[0], price[1]);
    for (int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            base = max(base, calc(price[i], price[j]));
        }
    }
    return base;
}

int main(){
    cin>>n>>b;
    for (int i=0; i<n; i++){
        cin>>price[i];
    }
    cout<<maximize();
}
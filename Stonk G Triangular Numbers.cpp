#include <bits/stdc++.h>
using namespace std;

int num;

string check(int angka){
    int newnum = 2*angka;
    newnum = sqrt(newnum);
    newnum = newnum*(newnum+1)/2;
    if (newnum == angka){return "YES";}
    else return "NO";
}

int main(){
    cin>>num;
    cout<<check(num);
}
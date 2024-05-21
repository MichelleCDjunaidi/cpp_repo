#include <bits/stdc++.h>
using namespace std;

string ori, check;
string revers = "";

int main(){
    cin>>ori>>check;
    for (int i=ori.length()-1; i>-1; i--){
        revers += ori[i];
    }
    if (check == revers){cout<<"YES";}
    else {cout<<"NO";}
}
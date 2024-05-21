#include <bits/stdc++.h>
using namespace std;

int n;
set<string> leaves;
string temp;

/*
3\n
a b\n
b c\n
c a\n
getline -> baca sampe ketemu \n
cin -> baca sampe ketemu nilai untuk variabel
*/

int main(){
    cin>>n; cin.ignore();
    for(int i=0; i<n; i++){
        getline(cin, temp);
        leaves.insert(temp);
    }
    cout<<leaves.size();
}
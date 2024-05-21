#include <bits/stdc++.h>
using namespace std;

string vowels= "aeiouyAEIOUY";
string conson= "bcdfghjklmnpqrstvwxzBCDFGHJKLMNPQRSTVWXZ";
string linecheck;
int idxv = -1;
int idxc = -1;

int main(){
    int idx=0;
    getline(cin, linecheck);
    for (char i: linecheck){
        if (vowels.find(i)!=string::npos){
            idxv=idx;
            idx+=1;
        }
        else if (conson.find(i)!=string::npos){
            idxc=idx;
            idx+=1;
        }
    }

    if (idxv>idxc){
        cout<<"YES";
        return 0;
    } 
    else cout<<"NO";
    //cout << isalpha('x') << endl;
}
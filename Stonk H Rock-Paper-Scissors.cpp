#include <bits/stdc++.h>
using namespace std;

string F, M, S;
string check[3];

string checkwin(string a, string b, string c){
    if (a=="paper" && b==c && c=="rock") return a;
    if (a=="rock" && b==c && c=="scissors") return a;
    if (a=="scissors" && b==c && c=="paper") return a;
    else return "NO";
}

int main(){
    cin>>F>>M>>S;
    int ans = -1;
    check[0] = checkwin(F, M, S);
    check[1] = checkwin(M, F, S);
    check[2] = checkwin(S, M, F);
    for (int i=0; i<3; i++){
        if (check[i]!="NO") {
            ans=i;
            break;
        }
    }

    if (ans==0) {
        cout<<"F";
        return 0;
    }
    if (ans==1) {
        cout<<"M";
        return 0;
    }
    if (ans==2) {
        cout<<"S";
        return 0;
    }
    else cout<<"?";
}
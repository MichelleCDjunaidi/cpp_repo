#include <bits/stdc++.h>
using namespace std;

string month[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
string cur;
int curmonth;
int calc;
int ans;

int main(){
    cin>>cur;
    cin>>calc;
    for (int i=0; i<12; i++){
        if (month[i]==cur) curmonth=i;
    }
    ans=(curmonth+calc)%12;
    cout<<month[ans];
}
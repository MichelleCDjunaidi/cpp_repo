#include <bits/stdc++.h>
using namespace std;

string numb;
string quest[3000];
string range[2];
int i;

void delimit(string left, string lim=" "){
    int start = 0;
    int end = left.find(lim);
    i=0;
    if(end=-1){
        quest[0]=left;
    }
    while(end!=-1){
        quest[i]= left.substr(start, end-start-1);
        cout<<left.substr(start, end-start-1);
        cout<< "hey";
        start = end + 1; //1 because ; and - is just 1. if makeshift, use lim.size()
        end = left.find(lim, start); //start karena perlu mulai search dari start LMAO kalau engga dia ambil yang di depan aja
        i += 1;
    }
}

int rangecount(string subleft, string lim2 =" "){
    int start = 0;
    int end = subleft.find(lim2);
    int val = 0;
    if (end>-1){
        range[0]= subleft.substr(start, end-start-1); //angka di kiri -
        range[1]= subleft.substr(end-start+1, subleft.size()-1); //angka di kanan
        int a =0;
        int b =0;
        stringstream fun(range[0]);
        fun>> a;
        stringstream fun1(range[1]);
        fun1>> b;
        val = b-a+1;
    }
    else{
        val = 1;
    }
    cout<<val;
    return val;
}

int main(){
    cin>>numb;
    int value = 0;
    delimit(numb, ";");
    for (int j=0; j<i; j++){
        value += rangecount(quest[j], "-");
    }
    cout<<value;
}
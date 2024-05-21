#include<bits/stdc++.h>
using namespace std;
int main (){
  int tc;
  cin>>tc;
  for(int i=1;i<=tc;i++){
    string s;
    cin>>s;
    long long ls=s.length();
    for(int j=0;j<ls;j++){
      if(s[j]=='0'){
        cout<<"zero";
      }else if(s[j]=='1'){
        cout<<"one";
      }else if(s[j]=='2'){
        cout<<"two";
      }else if(s[j]=='3'){
        cout<<"three";
      }else if(s[j]=='4'){
        cout<<"four";
      }else if(s[j]=='5'){
        cout<<"five";
      }else if(s[j]=='6'){
        cout<<"six";
      }else if(s[j]=='7'){
        cout<<"seven";
      }else if(s[j]=='8'){
        cout<<"eight";
      }else if(s[j]=='9'){
        cout<<"nine";
      }
      cout<<" ";
    }
    cout<<"\n";
  }
}


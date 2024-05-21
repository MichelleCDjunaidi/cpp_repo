//KEZIA
//SOAL A
#include <bits/stdc++.h>
using namespace std; 
int main (){
  
  string s;
  cin>>s;
  int ls= s.length();
  int now=1;
  for(int i=0;i<ls;i++){
  
    if(s[i]==s[i+1]){
      now++;
    }else{
      cout<<now<<s[i];
      now=1;
    }
  }
}

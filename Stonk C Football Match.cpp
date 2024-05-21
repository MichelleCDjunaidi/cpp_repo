#include <bits/stdc++.h>
using namespace std;

int n;
const int N = 1e3;
string match[N];
int count1, count2;
string team[2];
int result[N];

void findteam(){
    team[0]=match[0];
    for (int i=0; i<n; i++){
        if (match[i]!=team[0]) {
            team[1]=match[i];
            break;
        }
    }
}

string findwinner(string record[]){//record adalah suatu array
  count1=0;
  count2=0;
  for (int i=0; i<n; i++){
      if (record[i]==team[0]) count1+=1;
      if (record[i]==team[1]) count2+=1;
  }
  int result1 = max(count1,count2);
  if (result1 == count1) return team[0];
  return team[1];
}

int main(){
  cin>>n;
  for (int l=0; l<n; l++){
      cin>>match[l];
  }
  findteam();
  cout<<findwinner(match);
}
#include <bits/stdc++.h>
using namespace std;

int n, V;
const int A = 1e5;
double proportion[A], have[A];
double small;
int idx = 0;

void findsmall(){
  for (int i=0; i<n; i++){
    if (small>=have[i]) {
      small = have[i];
      idx = i;
    }
  }
}

double count(){
  double propsum =0;
  for (int i=0; i<n; i++){
    propsum += proportion[i];
  }
  double ratio = small/proportion[idx];
  if (propsum*ratio > V){
    return V;
  }
  else return propsum*ratio;
}

int main() {
  cin>>n>>V;
  for (int i=0; i<n; i++){
    cin>>proportion[i];
  }
  for (int i=0; i<n; i++){
    cin>>have[i];
  }
  small = have[0];
  findsmall();
  cout<<count();
}
#include <bits/stdc++.h>
using namespace std;

// SOAL G
int main() {
  int n;
  cin >> n;
  int num[n], doub[n], rare[n];
  for (int i = 0; i < n; i++) {
    cin >> num[i];
    doub[i] = num[i] * 2;
    rare[i] = sqrt(doub[i]) + 1;
  }
  
  for (int i = 0; i < n; i++) {
    if (doub[i] % rare[i] == 0) {
      cout << "YA";
    } else {
      cout << "TIDAK";
    }
    if(i!=n-1){
    	cout<<"\n";
	}
  } 
}

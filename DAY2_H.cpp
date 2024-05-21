#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int arah[n];
  int xPutar[n];
  for (int i = 0; i < n; i++) {
    string temp;
    cin >> temp >> xPutar[i];
    if (temp == "timur") { 
      arah[i] = 0;
    } else if (temp == "selatan") {
      arah[i] = 1;
    } else if (temp == "barat") {
      arah[i] = 2;
    } else {
      arah[i] = 3;
    }
  }
  
  for (int i = 0; i < n; i++) {
    xPutar[i] = xPutar[i]%4;
    arah[i] = (arah[i] + xPutar[i]) % 4;
  }
  
  for (int i = 0; i < n; i++) {
    if (arah[i] == 0) { 
      cout << "timur" ;
    } else if (arah[i] == 1) {
      cout << "selatan";
    } else if (arah[i] == 2) {
      cout << "barat" ;
    } else {
      cout << "utara" ;
    }
    if(i!=n-1){
    	cout<<"\n";
	}
  }
}

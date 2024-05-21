#include <iostream>
using namespace std;

int cases;
int arr[1010];

int count(int prime){
  int b = prime-1;
  if (b/2!=2) {
    return b/2;
  }
  else return b;
}
  
int main() {
	cin>>cases;
  for (int i=0; i<cases; i++){
    cin>>arr[i];
  }
  for (int j=0; j<cases; j++){
    cout<<"2 " <<count(arr[j])<< endl;
  }
}

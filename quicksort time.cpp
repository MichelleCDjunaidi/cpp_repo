#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int ar[N];
int tmp[N];
/*

void quicksort(int l, int r){
  if(l >= r)return;
  int piv = ar[rand() % (r - l + 1) + l];
  //biar ga deterministik/stuck dalam corner case
  int pl = l, pr = r;
  while(pl <= pr){
    while(pl <= pr && ar[pl] < piv)pl++;
    while(pr >= pl && ar[pr] > piv)pr--;
    if(pl <= pr){
      swap(ar[pl], ar[pr]);
      pl++, pr--;
    }
  }

  quicksort(l, pr);
  quicksort(pl, r);
}

void quicksort2(int l ,int r){
  if(l >= r)return;
  int piv = ar[(l + r) / 2];

  int pl = l, pr = r;
  for(int i = l; i <= r; i++){
    if(ar[i] < piv){
      tmp[pl] = ar[i];
      pl++;
    }else if(ar[i] > piv){
      tmp[pr] = ar[i];
      pr--;
    }
  }
  int fpl = pl;
  while(fpl <= pr){
    tmp[fpl] = piv;
    fpl++;
  }

  for(int i = l; i <= r; i++){
    ar[i] = tmp[i];
  }

  quicksort2(l, pl - 1);
  quicksort2(pr + 1, r);
}

void quicksort3(int l, int r){
  if(l >= r)return;
  int piv = ar[r];

  int pr = r - 1;
  for(int i = l; i <= pr;){
    if(ar[i] < piv){
      i++;
      continue;
    }

    swap(ar[i], ar[pr]); // i nya stay dulu
    pr--;
  }
  pr++;
  swap(ar[r], ar[pr]);

  quicksort3(l, pr - 1);
  quicksort3(pr + 1, r);
}

void mergesort(int l, int r){
  if(l == r)return;
  int m = (l + r) / 2;
  mergesort(l, m);
  mergesort(m + 1, r);

  int idx = l;
  int pl = l, pr = m + 1;
  while(pl <= m && pr <= r){
    if(ar[pl] < ar[pr]){
      tmp[idx++] = ar[pl++];
    }else{
      tmp[idx++] = ar[pr++];
    }
  }

  // Beres disini either data kiri abis atau data kanan abis
  // Data kiri abis -> pl > m, pr <= r
  // Data kanan abis -> pr > r, pl <= m
  while(pl <= m){ // Selama masih ada data di kiri, append di belakang
    tmp[idx++] = ar[pl++];
  }
  while(pr <= r){ // Selama masih ada data di kanan, append di belakang
    tmp[idx++] = ar[pr++];
  }

  for(int i = l; i <= r; i++) ar[i] = tmp[i];
}

// int main() {
// 	int n; cin >> n;
//   for(int i = 1; i <= n; i++){
//     ar[i] = rand() % 1000;
//     // cout << ar[i] << " ";
//     // cin >> ar[i];
//   }
//   // cout << endl;

//   mergesort(1, n);
//   for(int i = 1; i <= n; i++){
//     cout << ar[i] << " ";
//   }
//   cout << endl;
// }

*/

// void bubblesort(int n){
//   for(int j=1; j<=n-1; j++){
//     for(int i=1; i<=n-1; i++){
//       if (ar[i]>ar[i+1]){
//         swap(ar[i], ar[i+1]);
//         cost=cost+1;
//       }
//     }
//   }
// }

long long mergesort(int l, int r) {
    if (l == r)return 0;
    int m = (l + r) / 2;
    long long cost = mergesort(m + 1, r) + mergesort(l, m);

    int place = 0;

    int idx = l;
    int pl = l, pr = m + 1;
    while (pl <= m && pr <= r) {
        if (ar[pl] < ar[pr]) {
            tmp[idx++] = ar[pl++];
            place += 1;
        }
        else {
            tmp[idx++] = ar[pr++];
            cost += m - l + 1 - place;
        }
    }
    while (pl <= m) {
        tmp[idx++] = ar[pl++];
    }
    while (pr <= r) {
        tmp[idx++] = ar[pr++];
    }
    for (int i = l; i <= r; i++) ar[i] = tmp[i];
    return cost;
}

int main() {
    int testcase; cin >> testcase;
    for (int i = 1; i <= testcase; i++) {
        int n; cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> ar[i];
        }

        cout << mergesort(1, n) << endl;
    }

    sort(ar, ar + n);
}

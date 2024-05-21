// #include <iostream>
// using namespace std;

// const int N = 15;

// int n; 
// int ans[N];
// bool used[N];

// void backtrack(int idx){
//   if(idx > n){
//     for(int i = 1; i <= n; i++){
//       cout << ans[i] << " ";
//     }
//     cout << endl;
//     return;
//   }

//   // Coba taro angka di posisi ke-idx pada array ans
//   for(int i = 1; i <= n; i++){
//     // coba taro angka i
//     if(used[i])continue; // udah pernah dipake di rekursif sebelumnya

//     ans[idx] = i;
//     used[i] = true;
//     backtrack(idx + 1);
//     // udah beres -> semua kemungkinannya udah dicobain
//     used[i] = false;
//   }
// }

// int main() {
// 	cin >> n;

//   backtrack(1);
// }

/*
Input N -> outputin semua N! permutasi yang mungkin
-------------------
Input N, K -> outputin semua kemungkinan NcK yang mungkin

(N, K) 4 2
Output:
1 2
1 3
1 4
2 3
2 4
3 4

*/

#include <iostream>
using namespace std;

const int N = 15;

int n, k;
int ans[N];
bool used[N];

void backtrack(int idx, int last) {
    if (idx > k) {
        for (int i = 1; i <= k; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = last + 1; i <= n; i++) {
        if (used[i])continue;

        ans[idx] = i;
        used[i] = true;
        backtrack(idx + 1, i);
        used[i] = false;
    }

}

int main() {
    cin >> n >> k;

    backtrack(1, 0);
}
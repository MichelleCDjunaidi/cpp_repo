#include<bits/stdc++.h>
using namespace std;

const int N = 15;

int n;

// print('*' * 10)

void backtrack(int j) {
    if (j == 0)return;

    string bintang;
    bintang = "";

    backtrack(j - 1);
    for (int i = 1; i <= j; i++) {
        bintang += "*";
    }
    cout << bintang << endl;
    backtrack(j - 1);

}

int main() {
    cin >> n;

    backtrack(n);
}
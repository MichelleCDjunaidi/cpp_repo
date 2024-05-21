#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    // please don't forget vector size smh
    vector<long> inputs(n);
    for(int i = 0; i< n; i++) {
        cin >> inputs[i];
    }
    int prev_int = inputs[0];
    int curr_int;
    long moves = 0;
    for (int j = 0; j < n; j++) {
        curr_int = inputs[j];
        if (prev_int > curr_int) {
            moves = moves + prev_int - curr_int;
        }
        else if (prev_int < curr_int) {
            prev_int = curr_int;    
        }
    }
    cout << moves;
}
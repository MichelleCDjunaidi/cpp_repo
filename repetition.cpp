#include <bits/stdc++.h>

using namespace std;

int main() {
    string DNA;
    cin >> DNA;
    int n = DNA.length();
    vector<char> inputs(n);
    for (int i=0; i<n ; i++) {
        inputs[i] = DNA[i];
    }
    char curr_char;
    char prev_char = inputs[0];
    long max_length = 0;
    long curr_length = 0;
    for (int j=0; j<n ; j++) {
        curr_char = inputs[j];
        if (curr_char != prev_char) {
            if (curr_length > max_length) {
                max_length = curr_length;
            }
            curr_length = 1;
            prev_char = curr_char;
        }
        else {
            curr_length += 1;
        }
    }
    // forgot last checks
    if (curr_length > max_length) {
        max_length = curr_length;
    }    
    cout << max_length;
}
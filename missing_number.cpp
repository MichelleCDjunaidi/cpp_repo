#include <iostream>
using namespace std;

int main() {
    // Write C++ code here
    long n;
    long b;
    cin >> n;
    long total = n*(n+1)/2;
    for (long i=0; i<n-1; i++) {
        cin >> b;
        total -= b;
    }

    cout << total;
}
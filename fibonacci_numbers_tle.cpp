#include <iostream>
#include <array>


using namespace std;

// alias array of size 2*2 to matrix
using matrix = array<int, 4>;
using math_vector = array<long, 2>;

const int MOD = 1e9 + 7;

// auto allows the compiler to automatically dynamically type the reference ig
// function multiply, returns vector data type
math_vector matrix_mult(const matrix& mat, const math_vector& vec) {
    math_vector vec_result;
    // lambda expression...................
    // &a to allow access to a's memory
    auto matrix_not = [&mat](size_t row, size_t col) {return mat[row*2 + col];};
    vec_result[0] = matrix_not(0, 0)*vec[0] + matrix_not(0, 1)*vec[1];
    vec_result[1] = matrix_not(1, 0)*vec[0] + matrix_not(1, 1)*vec[1];
    if (vec_result[0] >= MOD) {
        vec_result[0] -= MOD;
    }
    if (vec_result[1] >= MOD) {
        vec_result[1] -= MOD;
    }
    return vec_result;
}

long fibo(long n) {
    // note: unintuitive way to do this; don't do it next time
    // fibo_gen and fibo_init should be in main instead

    // static to allow lifetime access to the same space + prev results
    // otherwise will always be initialized
    // alternatively, do this on main and pass it into fibo as a function call
    // so it'd be fibo(long n, const& fibo_gen, const& fibo_results)
    // but we did that already in previous solutions
    // vector result would be [f(n+1), f(n)]
    static const matrix fibo_gen{1, 1, 1, 0};
    static const math_vector fibo_init{1, 0};
    math_vector result = fibo_init;
    for (int i=0; i<n ; i++) {
        result = matrix_mult(fibo_gen, result);
    }
    return result[1];
}

int main() {
    long n;
    cin >> n;
    cout << fibo(n);
}
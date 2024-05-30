#include <iostream>
#include <array>


using namespace std;

// alias array of size 2*2 to matrix
using matrix = array<long long, 4>;

const long long MOD = 1e9 + 7;

matrix matrix_mult(const matrix& mat1, const matrix& mat2) {
    matrix mat_result;
    // lambda expression...................
    // &a to allow access to a's memory
    auto mat1_nota = [&mat1](size_t row, size_t col) {return mat1[row*2 + col];};
    auto mat2_nota = [&mat2](size_t row, size_t col) {return mat2[row*2 + col];};

    mat_result[0] = (mat1_nota(0, 0) * mat2_nota(0, 0) + mat1_nota(0, 1) * mat2_nota(1, 0)) % MOD;
    mat_result[1] = (mat1_nota(0, 0) * mat2_nota(0, 1) + mat1_nota(0, 1) * mat2_nota(1, 1)) % MOD;
    mat_result[2] = (mat1_nota(1, 0) * mat2_nota(0, 0) + mat1_nota(1, 1) * mat2_nota(1, 0)) % MOD;
    mat_result[3] = (mat1_nota(1, 0) * mat2_nota(0, 1) + mat1_nota(1, 1) * mat2_nota(1, 1)) % MOD;

    return mat_result;
}

matrix matrix_pow(matrix& base, long long exp){
    matrix result = {1, 0, 0, 1};
    while (exp > 0) {
        if (exp % 2 == 1){
            // oh, this advances the fibo by one
            // since result is stored in itself
            result = matrix_mult(result, base);
        }
        base = matrix_mult(base, base);
        exp /= 2;
    }
    return result;
}

long long fibo(long long n) {
    if (n==0) { return 0; }
    static matrix fibo_gen{1, 1, 1, 0};
    matrix result_matrix = matrix_pow(fibo_gen, n-1);
    return result_matrix[0];
}

int main() {
    long long n;
    cin >> n;
    cout << fibo(n);
}
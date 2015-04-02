#include <iostream>
#include <algorithm>
#include <valarray>
#include <cassert>
using namespace std;

// 行列
struct matrix {
  int row, col;
  valarray<long long> a;
  matrix(int N, int M) {
    a = valarray<long long>(N * M);
    row = N;
    col = M;
  }
  bool operator<( const matrix& right ) const { // 使わないけどtupleに必要
    return row < right.row;
  }
  bool operator>( const matrix& right ) const { // 使わないけどtupleに必要
    return row > right.row;
  }
};

matrix multiply(matrix A, matrix B) {
  assert(A.col == B.row);
  int N = A.col;
  matrix C(A.row, B.col);
  for (auto i=0; i<C.row; i++) {
    for (auto j=0; j<C.col; j++) {
      C.a[i*C.col + j] = ((valarray<long long>)A.a[slice(i*A.col, N, 1)] *
                          (valarray<long long>)B.a[slice(j, N, B.col)]).sum();
    }
  }
  return C;
}

matrix inverse(matrix A, matrix B) { // A^{-1} B を出力
  assert(A.row == A.col);
  assert(A.col == B.row);
  int N = A.row;
  int M = B.col;
  for (auto i=0; i<N; i++) {
    long long taikaku = A.a[i*N+i];
    for (auto k=0; k<N; k++) {
      if (i == k) continue;
      long long keisu = A.a[k*N+i]/taikaku;
      // A.a[k*N+i] = 0;
      for (auto j=i+1; j<N; j++) {
        A.a[k*N+j] = A.a[k*N+j] - keisu * A.a[i*N+j];
      }
      for (auto j=0; j<M; j++) {
        B.a[k*M+j] = B.a[k*M+j] - keisu * B.a[i*M+j];
      }
    }
  }
  for (auto i=0; i<N; i++) {
    long long taikaku = A.a[i*N+i];
    for (auto j=0; j<M; j++) {
      B.a[i*M+j] = B.a[i*M+j]/taikaku;
    }
  }
  return B;
}

matrix transposed(matrix A) {
  matrix B = matrix(A.col, A.row);
  for (auto i=0; i<B.row; i++) {
    for (auto j=0; j<B.col; j++) {
      B.a[i*B.col + j] = A.a[j*A.col + i];
    }
  }
  return B;
}

long long M = 1000;

matrix mod_multiply(matrix A, matrix B) {
  assert(A.col == B.row);
  int N = A.col;
  matrix C(A.row, B.col);
  for (auto i=0; i<C.row; i++) {
    for (auto j=0; j<C.col; j++) {
      C.a[i*C.col + j] = ((valarray<long long>)A.a[slice(i*A.col, N, 1)] *
                          (valarray<long long>)B.a[slice(j, N, B.col)]).sum()%M;
    }
  }
  return C;
}

matrix mod_pow(matrix A, long long n) { // n \geq 1
  if (n%2 == 0) {
    matrix B = mod_pow(A, n/2);
    return mod_multiply(B, B);
  } else if (n == 1) {
    return A;
  } else {
    return mod_multiply(A, mod_pow(A, n-1));
  }
}

long long N;

void input() {
  cin >> N;
}

void output() {
  matrix X(2, 2);
  X.a[0] = 3;
  X.a[1] = 5;
  X.a[2] = 1;
  X.a[3] = 3;
  matrix Y = mod_pow(X, N);
  printf("%03lld\n", (Y.a[0] * 2 + M - 1)%M);
}

int main() {
  int T;
  cin >> T;
  for (auto t=1; t<=T; t++) {
    cout << "Case #" << t << ": "; 
    input();
    output();
  }
}

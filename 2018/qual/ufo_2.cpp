/**
 * File    : ufo_2.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-4-9 8:36:24
 * Powered by Visual Studio Code
 */

#define mattype double

#include <iostream>
#include <iomanip>   // << fixed << setprecision(xxx)
#include <algorithm> // do { } while ( next_permutation(A, A+xxx) ) ;
#include <vector>
#include <string> // to_string(nnn) // substr(m, n) // stoi(nnn)
#include <complex>
#include <tuple>
#include <queue>
#include <stack>
#include <map> // if (M.find(key) != M.end()) { }
#include <set>
#include <random> // random_device rd; mt19937 mt(rd());
#include <valarray>
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define DEBUG 0 // change 0 -> 1 if we need debug.

typedef long long ll;

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
// const ll M = 1000000007;

struct matrix {
  int row, col;
  valarray<mattype> a;
  matrix(){}
  matrix(int N, int M)
  {
    a = valarray<mattype>(N * M);
    row = N;
    col = M;
  }
  bool operator<(const matrix& right) const {
    if (row != right.row) {
      return row < right.row;
    }
    if (col != right.col) {
      return col < right.col;
    }
    for (auto i=0; i<row*col; i++) {
      if (a[i] != right.a[i]) {
        return a[i] < right.a[i];
      }
    }
    return false;
  }
  bool operator>(const matrix& right) const {
    if (row != right.row) {
      return row > right.row;
    }
    if (col != right.col) {
      return col > right.col;
    }
    for (auto i=0; i<row*col; i++) {
      if (a[i] != right.a[i]) {
        return a[i] > right.a[i];
      }
    }
    return false;
  }
  bool operator==(const matrix& right) const {
    if (row != right.row) return false;
    if (col != right.col) return false;
    for (auto i=0; i<row*col; i++) {
      if (a[i] != right.a[i]) {
        return false;
      }
    }
    return true;
  }
  string to_s() const {
    string res = "";
    for (auto i=0; i<row; i++) {
      for (auto j=0; j<col; j++) {
        res += to_string(a[i*col+j]);
        if (j != col-1) res += " ";
      }
      if (i != row-1) res += "\n";
    }
    return res;
  }
  void input() {
    for (auto i=0; i<row*col; i++) {
      cin >> a[i];
    }
  }
};

ostream& operator<<(ostream& s, const matrix A) {
  return s << A.to_s();
}

matrix multiply(matrix A, matrix B) {
  assert(A.col == B.row);
  int N = A.col;
  matrix C(A.row, B.col);
  for (auto i=0; i<C.row; i++) {
    for (auto j=0; j<C.col; j++) {
      C.a[i*C.col + j] = ((valarray<mattype>)A.a[slice(i*A.col, N, 1)] *
                          (valarray<mattype>)B.a[slice(j, N, B.col)]).sum();
    }
  }
  return C;
}

matrix X[3];

void solve2(double A)
{
  double oneparsqrt2 = 1 / sqrt(2);
  matrix rotate_for_y = matrix(3, 3);
  rotate_for_y.a = {
    oneparsqrt2, 0, -oneparsqrt2,
    0, 1, 0,
    oneparsqrt2, 0, oneparsqrt2
  };
  for (auto k = 0; k < 3; k++)
  {
    X[k] = multiply(rotate_for_y, X[k]);
  }
  double costheta, sintheta;
  sintheta = (sqrt(2) * A - sqrt(3 - A * A)) / 3;
  costheta = A - sqrt(2) * sintheta;
  matrix rotate_for_z = matrix(3, 3);
  rotate_for_z.a = {
    costheta, -sintheta, 0,
    sintheta, costheta, 0,
    0, 0, 1
  };
  for (auto k = 0; k < 3; k++)
  {
    X[k] = multiply(rotate_for_z, X[k]);
  }
}

void solve()
{
  X[0] = matrix(3, 1);
  X[0].a = {0.5, 0, 0};
  X[1] = matrix(3, 1);
  X[1].a = {0, 0.5, 0};
  X[2] = matrix(3, 1);
  X[2].a = {0, 0, 0.5};
  double A;
  cin >> A;
  solve2(A);
  for (auto k = 0; k < 3; k++)
  {
    for (auto j = 0; j < 3; j++)
    {
      cout << fixed << setprecision(12) << X[k].a[j];
      if (j < 2)
      {
        cout << " ";
      }
      else
      {
        cout << endl;
      }
    }
  }
}

int main()
{
  int T;
  cin >> T;
  for (auto i = 0; i < T; i++)
  {
    cout << "Case #" + to_string(i + 1) + ": " << endl;
    solve();
  }
}
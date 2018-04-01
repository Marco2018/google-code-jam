#include <iostream>
#include <iomanip> // << fixed << setprecision(xxx)
#include <algorithm> // do { } while ( next_permutation(A, A+xxx) ) ;
#include <vector>
#include <string> // to_string(nnn) // substr(m, n) // stoi(nnn)
#include <complex>
#include <tuple> // get<n>(xxx)
#include <queue>
#include <stack>
#include <map> // if (M.find(key) != M.end()) { }
#include <set> // S.insert(M);
// if (S.find(key) != S.end()) { }
// for (auto it=S.begin(); it != S.end(); it++) { }
// auto it = S.lower_bound(M);
#include <random> // random_device rd; mt19937 mt(rd());
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib> // atoi(xxx)
using namespace std;

#define DEBUG 0 // change 0 -> 1 if we need debug.
// insert #if<tab> by my emacs. #if DEBUG == 1 ... #end

typedef long long ll;

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
// const ll M = 1000000007;

typedef tuple<int, int> kukan;

int N, P;
int R[60];
int Q[60][60];
kukan k[60][60];

kukan make_kukan(double g, double x) {
  double maxi = x * 1.1;
  double mini = x * 0.9;
  return kukan(ceil(g/maxi), floor(g/mini));
}

void solve1() {
  int ans = 0;
  for (auto i = 0; i < P; ++i) {
    if (get<0>(k[0][i]) <= get<1>(k[0][i])) ans++;
  }
  cout << ans << endl;
}

void solve2() {
  int c[10];
  for (auto i = 0; i < P; ++i) {
    c[i] = i;
  }
  int ans = 0;
  do {
    int res = 0;
    for (auto i = 0; i < P; ++i) {
      int mini = max(get<0>(k[0][i]), get<0>(k[1][c[i]]));
      int maxi = min(get<1>(k[0][i]), get<1>(k[1][c[i]]));
      if (mini <= maxi) res++;
    }
    ans = max(ans, res);
  } while (next_permutation(c, c+P));
  cout << ans << endl;
}

void solve() {
  cin >> N >> P;
  for (auto i = 0; i < N; ++i) {
    cin >> R[i];
  }
  for (auto i = 0; i < N; ++i) {
    for (auto j = 0; j < P; ++j) {
      cin >> Q[i][j];
      k[i][j] = make_kukan(Q[i][j], R[i]);
    }
  }
  if (N == 1) {
    solve1();
  } else {
    solve2();
  }
}

int main () {
  int T;
  cin >> T;
  for (auto i = 0; i < T; ++i) {
    cout << "Case #" << i+1 << ": ";
    solve();
  }
}

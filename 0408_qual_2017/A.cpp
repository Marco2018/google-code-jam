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

string S;
int K;
int N;
bool cake[1010];

void show_cake() {
  for (auto i = 0; i < N; ++i) {
    cerr << (cake[i] ? '+' : '-');
    if (i == N-1) cerr << endl;
  }
}

void solve() {
  cin >> S >> K;
  N = (int)S.size();
  for (auto i = 0; i < N; ++i) {
    cake[i] = (S[i] == '+');
  }
  //show_cake();
  int ans = 0;
  for (auto i = 0; i + K <= N; ++i) {
    if (!cake[i]) {
      ++ans;
      for (auto j = i; j < i + K; ++j) {
        cake[j] = !cake[j];
      }
      //show_cake();
    }
  }
  for (auto i = 0; i < N; ++i) {
    if (!cake[i]) {
      cout << "IMPOSSIBLE" << endl;
      return;
    }
  }
  cout << ans << endl;
}

int main () {
  int T;
  cin >> T;
  for (auto i = 0; i < T; ++i) {
    cout << "Case #" << i+1 << ": ";
    solve();
  }
}

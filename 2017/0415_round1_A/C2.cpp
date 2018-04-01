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

int Hd, Ad, Hk, Ak, B, D;

int infty = 2000;

void solve() {
  cin >> Hd >> Ad >> Hk >> Ak >> B >> D;
  int ans = infty;
  for (auto i = 0; i <= 100; ++i) {
    for (auto j = 0; j <= 100; ++j) {
      int b = i;
      int d = j;
      int res = 0;
      int hd = Hd;
      int ad = Ad;
      int hk = Hk;
      int ak = Ak;
      while (res < infty) {
        if (hk - ad <= 0) {
          hk -= ad;
        } else if (hd - ak <= 0) {
          hd = Hd;
        } else if (d > 0) {
          ak -= D;
          if (ak < 0) ak = 0;
          d--;
        } else if (b > 0) {
          ad += B;
          b--;
        } else {
          hk -= ad;
        }
        res++;
        if (hk <= 0) break;
        hd -= ak;
        if (hd <= 0) {
          res = infty;
          break;
        }
      }
      if (res >= infty) continue;
      ans = min(ans, res);
    }
  }
  if (ans == infty) {
    cout << "IMPOSSIBLE" << endl;
  } else {
    cout << ans << endl;
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

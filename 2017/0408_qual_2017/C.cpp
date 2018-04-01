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

vector<ll> V;

void init() {
  for (auto i = 0; i < 61; ++i) {
    V.push_back(((ll)1 << i) - 1);
    // cerr << V[i] << endl;
  }
}

ll N;
ll K;

void output_answer(ll n) {
  --n;
  cout << n - n/2 << " " << n/2 << endl;
}

void solve() {
  cin >> N >> K;
  --K;
  for (auto i = 0; i < 61; ++i) {
    if (K < V[i+1]) {
      ll k = K - V[i];
      ll X = (V[i+1] - V[i]);
      ll Y = N - V[i];
      ll b = (X - Y%X)%X;
      ll x = (Y+b)/X;
      ll a = X - b;
      if (k < a) {
        output_answer(x);
      } else {
        output_answer(x-1);        
      }
      return;
    }
  }
}

int main () {
  init();
  int T;
  cin >> T;
  for (auto i = 0; i < T; ++i) {
    cout << "Case #" << i+1 << ": ";
    solve();
  }
}

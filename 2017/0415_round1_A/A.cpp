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

int R, C;
string S[100];
bool used[26];

void solve() {
  cin >> R >> C;
  for (auto i = 0; i < R; ++i) {
    cin >> S[i];
  }
  fill(used, used+26, false);
  for (auto i = 0; i < R; ++i) {
    for (auto j = 0; j < C; ++j) {
      used[S[i][j] - 'A'] = true;
    }
  }
  for (auto l = 0; l < 26; ++l) {
    if (!used[l]) continue;
    char c = l + 'A';
    int maxi_x = -1;
    int mini_x = 1000;
    int maxi_y = -1;
    int mini_y = 1000;
    for (auto i = 0; i < R; ++i) {
      for (auto j = 0; j < C; ++j) {
        if (S[i][j] == c) {
          maxi_x = max(maxi_x, i);
          mini_x = min(mini_x, i);
          maxi_y = max(maxi_y, j);
          mini_y = min(mini_y, j);          
        }
      }
    }
    for (auto i = mini_x; i <= maxi_x; ++i) {
      for (auto j = mini_y; j <= maxi_y; ++j) {
        if (S[i][j] != c) {
          assert(S[i][j] == '?');
          S[i][j] = c;
        }
      }      
    }
  }
  
}

int main () {
  int T;
  cin >> T;
  for (auto i = 0; i < T; ++i) {
    cout << "Case #" << i+1 << ": " << endl;
    solve();
  }
}

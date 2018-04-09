/**
 * File    : saving.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-4-7 10:55:29
 * Powered by Visual Studio Code
 */

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

ll D;
string P;

ll calc(string S)
{
  ll now = 1;
  ll res = 0;
  for (auto x : S)
  {
    if (x == 'C')
    {
      now *= 2;
    }
    else
    {
      res += now;
    }
  }
  return res;
}

void solve()
{
  cin >> D >> P;
  int cnt = 0;
  int size = P.length();
  while (true)
  {
#if DEBUG == 1
    cerr << "calc(" << P << ") = " << calc(P) << endl;
#endif
    if (calc(P) <= D)
    {
      cout << cnt << endl;
      return;
    }
    bool swapped = false;
    for (auto i = size - 2; i >= 0; i--)
    {
      if (P[i] == 'C' && P[i + 1] == 'S')
      {
        swap(P[i], P[i + 1]);
        cnt++;
        swapped = true;
        break;
      }
    }
    if (!swapped)
      break;
  }
  cout << "IMPOSSIBLE" << endl;
}

int main()
{
  int T;
  cin >> T;
  for (auto i = 0; i < T; i++)
  {
    cout << "Case #" + to_string(i + 1) + ": ";
    solve();
  }
}
/**
 * File    : ant2.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-5-6 13:24:21
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
const ll infty = 1000000000000007;

int N;
ll W[100010];
ll DP[200];

void solve()
{
  cin >> N;
  for (auto i = 0; i < N; i++)
  {
    cin >> W[i];
  }
  fill(DP, DP + 200, infty);
  DP[0] = 0;
  for (auto i = 0; i < N; i++)
  {
    for (auto j = 199; j >= 1; j--)
    {
      if (DP[j - 1] <= 6 * W[i])
      {
        DP[j] = min(DP[j], DP[j - 1] + W[i]);
      }
    }
  }
  for (auto i = 199; i >= 0; i--)
  {
    if (DP[i] < infty)
    {
      cout << i << endl;
      return;
    }
  }
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
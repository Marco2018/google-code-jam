/**
 * File    : lollipop.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-5-5 18:24:04
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

int N;
int cnt[210];
bool sold[210];
double prob[210];

void solve()
{
  cin >> N;
  fill(cnt, cnt + 210, 0);
  fill(sold, sold + 210, false);
  for (auto i = 0; i < N; i++)
  {
    bool used[210];
    fill(used, used + 210, false);
    int D;
    cin >> D;
    if (D == 0)
    {
      cout << -1 << endl;
      continue;
    }
    for (auto j = 0; j < D; j++)
    {
      int t;
      cin >> t;
      used[t] = true;
      cnt[t]++;
    }
    int sum = 0;
    for (auto j = 0; j < N; j++)
    {
      sum += cnt[j];
    }
    for (auto j = 0; j < N; j++)
    {
      prob[j] = cnt[j] / (double)sum;
    }
    double mini = 2;
    int mini_i = -1;
    for (auto j = 0; j < N; j++)
    {
      if (sold[j] || !used[j])
      {
        continue;
      }
      if (mini > prob[j])
      {
        mini = prob[j];
        mini_i = j;
      }
    }
    cout << mini_i << endl;
    if (mini_i >= 0)
    {
      sold[mini_i] = true;
    }
  }
}

int main()
{
  int T;
  cin >> T;
  for (auto i = 0; i < T; i++)
  {
    solve();
  }
}
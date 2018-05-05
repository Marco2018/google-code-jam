/**
 * File    : word.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-5-5 18:05:17
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
int L;
string S[2010];
set<string> X;
set<string> Y[10];
int cnt;
string ans;

void dfs(string str)
{
  if (cnt > N)
    return;
  if ((int)str.length() == L)
  {
    if (X.find(str) == X.end())
    {
      ans = str;
      cnt = N + 1;
    }
    else
    {
      cnt++;
    }
    return;
  }
  for (auto x : Y[str.length()])
  {
    dfs(str + x);
  }
}

void solve()
{
  cin >> N >> L;
  cnt = 0;
  ans = "";
  X.clear();
  for (auto i = 0; i < L; i++)
  {
    Y[i].clear();
  }
  for (auto i = 0; i < N; i++)
  {
    cin >> S[i];
    X.insert(S[i]);
    for (auto j = 0; j < L; j++)
    {
      Y[j].insert(S[i].substr(j, 1));
    }
  }
  dfs("");
  if (ans == "")
  {
    cout << "-" << endl;
  }
  else
  {
    cout << ans << endl;
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
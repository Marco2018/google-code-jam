/**
 * File    : trouble.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-4-7 11:36:31
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

vector<int> fast_trouble(vector<int> L)
{
  vector<int> X[2];
  for (auto i = 0; i < (int)L.size(); i++)
  {
    X[i % 2].push_back(L[i]);
  }
  for (auto k = 0; k < 2; k++)
  {
    sort(X[k].begin(), X[k].end());
  }
  vector<int> LL;
  int l = X[0].size();
  for (auto i = 0; i < l; i++)
  {
    for (auto k = 0; k < 2; k++)
    {
      if (i < (int)X[k].size())
        LL.push_back(X[k][i]);
    }
  }
  return LL;
}

int ok(vector<int> L)
{
  for (auto i = 0; i < (int)L.size()-1; i++)
  {
    if (L[i] > L[i+1])
      return i;
  }
  return -1;
}

int N;
vector<int> L;
vector<int> LL;

void solve()
{
  cin >> N;
  L.clear();
  for (auto i = 0; i < N; i++)
  {
    int x;
    cin >> x;
    L.push_back(x);
  }
  LL = fast_trouble(L);
  int ans = ok(LL);
  if (ans == -1)
  {
    cout << "OK" << endl;
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
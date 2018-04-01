/**
 * File    : bathroom_stalls.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-4-1 18:30:39
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

ll N;
ll K;

void solve()
{
  cin >> N >> K;
  map<ll, ll> M;
  M[N] = 1;
  ll sum = 0;
  while (sum < K)
  {
    auto it = max_element(M.begin(), M.end());
    ll len = it->first;
    ll num = it->second;
    ll newlen1 = (len-1) / 2;
    ll newlen2 = (len-1) - newlen1;
    M.erase(it);
    if (M.find(newlen1) == M.end() && newlen1 > 0)
    {
      M[newlen1] = num;
    }
    else if (newlen1 > 0)
    {
      M[newlen1] += num;
    }
    if (M.find(newlen2) == M.end() && newlen2 > 0)
    {
      M[newlen2] = num;
    }
    else if (newlen2 > 0)
    {
      M[newlen2] += num;
    }
    if (sum + num < K)
    {
      sum += num;
    }
    else
    {
      if (newlen1 < newlen2)
        swap(newlen1, newlen2);
      cout << newlen1 << " " << newlen2 << endl;
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
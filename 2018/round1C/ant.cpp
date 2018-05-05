/**
 * File    : ant.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-5-5 19:06:38
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
ll W[100010];
int visited[10010];

void solve()
{
  cin >> N;
  for (auto i = 0; i < N; i++)
  {
    cin >> W[i];
  }
  fill(visited, visited + 10010, -1);
  visited[0] = 0;
  for (auto i = 0; i < N; i++)
  {
    for (auto j = 6 * W[i]; j >= 0; j--)
    {
      if (visited[j] >= 0)
      {
        visited[j + W[i]] = max(visited[j + W[i]], visited[j] + 1);
      }
    }
  }
  int maxi = 0;
  for (auto i = 0; i < 10010; i++)
  {
    maxi = max(maxi, visited[i]);
  }
  cout << maxi << endl;
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
/**
 * File    : senate_evacuation.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-4-1 16:48:32
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
int P[1010];
typedef tuple<int, string> party;
vector<string> ans;

void solve()
{
  cin >> N;
  int sum = 0;
  ans.clear();
  for (auto i = 0; i < N; i++)
  {
    cin >> P[i];
    sum += P[i];
  }
  vector<party> V;
  for (auto i = 0; i < N; i++)
  {
    string T = string{(char)('A' + i)};
    V.push_back(party(P[i], T));
  }
  while (sum > 0)
  {
    sort(V.begin(), V.end());
    reverse(V.begin(), V.end());
    if (get<0>(V[0]) > get<0>(V[1]) || (sum % 2 == 1 && get<0>(V[0]) == get<0>(V[1])))
    {
      get<0>(V[0])--;
      sum--;
      ans.push_back(get<1>(V[0]));
    }
    else
    {
      get<0>(V[0])--;
      get<0>(V[1])--;
      sum -= 2;
      ans.push_back(get<1>(V[0]) + get<1>(V[1]));
    }
  }
  int SIZE = ans.size();
  for (auto i = 0; i < SIZE; i++)
  {
    cout << ans[i];
    if (i < SIZE - 1)
      cout << " ";
    else
      cout << endl;
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
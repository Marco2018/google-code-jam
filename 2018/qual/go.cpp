/**
 * File    : go.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-4-7 12:05:55
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

bool ok[15][15];
int A, L;

bool flush(int x, int y)
{
  cout << x+1 << " " << y+1 << endl;
  int xx, yy;
  cin >> xx >> yy;
  if (xx == 0 && yy == 0)
  {
    return true;
  }
  else
  {
    assert(xx > 0 && yy > 0);
    // assert(abs(x + 1 - xx) <= 1 && abs(y + 1 - yy) <= 1);
    ok[xx - 1][yy - 1] = true;
#if DEBUG == 1
    if (x == 10 && y == 13) {
      cerr << x << " " << y << " " << xx - 1 << " " << yy - 1 << endl;
      cerr << "Field: " << endl;
      for (auto i = 0; i < L; i++)
      {
        for (auto j = 0; j < L; j++)
        {
          cerr << ok[i][j];
        }
        cerr << endl;
      }
    }
#endif
    return false;
  }
}

void solve()
{
  cin >> A;
  if (A == 20)
  {
    L = 5;
  }
  else
  {
    assert(A == 200);
    L = 15;
  }
  fill(&ok[0][0], &ok[0][0] + 15 * 15, false);
  for (auto i = 0; i < L-2; i++)
  {
    for (auto j = 0; j < L-2; j++)
    {
      while (!ok[i][j] && !flush(i+1, j+1))
      {
        //
      }
    }
  }
  for (auto j = 0; j < L-2; j++)
  {
    while (!(ok[L-2][j] && ok[L-1][j]) && !flush(L - 2, j + 1))
    {
      //
    }
  }
  for (auto j = 0; j < L-2; j++)
  {
    while (!(ok[j][L-2] && ok[j][L-1]) && !flush(j + 1, L - 2))
    {
#if DEBUG == 1
      cerr << "ok[" << j << "][" << L - 2 << "] = "
            << ok[j][L-2] << ", "
            << "ok[" << j << "][" << L - 1 << "] = "
            << ok[j][L - 1] << endl;
#endif
    }
  }
  while (!(ok[L-2][L-2] && ok[L-2][L-1] && ok[L-1][L-1] && ok[L-1][L-2])
          && !flush(L - 2, L - 2))
  {
    //
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
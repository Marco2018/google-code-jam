/**
 * File    : number_guessing.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-4-1 16:22:54
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

int T;
int A, B, N;

int say(int x)
{
  cout << x << endl;
  string S;
  cin >> S;
  if (S == "CORRECT")
    return 0;
  if (S == "TOO_BIG")
    return 1;
  if (S == "TOO_SMALL")
    return 2;
  else
    return 3;
}

int main()
{
  cin >> T;
  for (auto k = 0; k < T; k++)
  {
    cin >> A >> B >> N;
    if (say(B) == 0)
      continue;
    int lb = A;
    int ub = B;
    while (ub - lb > 1)
    {
      bool determined = false;
      int t = (ub + lb) / 2;
      int a = say(t);
      assert(a < 3);
      if (a == 0)
      {
        determined = true;
      }
      else if (a == 1)
      {
        ub = t;
      }
      else
      {
        lb = t;
      }
      if (determined)
        break;
    }
  }
}
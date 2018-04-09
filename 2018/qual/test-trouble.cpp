/**
 * File    : test-trouble.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-4-7 11:17:25
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

vector<int> trouble(vector<int> L)
{
  bool done = false;
  while (!done)
  {
    done = true;
    assert((int)L.size() >= 3);
    for (auto i = 0; i < (int)L.size() - 2; i++)
    {
      if (L[i] > L[i+2])
      {
        done = false;
        swap(L[i], L[i + 2]);
      }
    }
  }
  return L;
}

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

bool ok(vector<int> L)
{
  for (auto i = 0; i < (int)L.size()-1; i++)
  {
    if (L[i] > L[i+1])
      return false;
  }
  return true;
}

int main()
{
  random_device rd;
  mt19937 mt(rd());
  int size = 8;
  for (auto i = 0; i < 100; i++)
  {
    vector<int> L(size);
    for (auto j = 0; j < size; j++)
    {
      L[j] = rd() % size;
    }
    vector<int> LL = trouble(L);
    assert(LL == fast_trouble(L));
    for (auto j = 0; j < size; j++)
    {
      cerr << L[j] << " ";
    }
    cerr << " -> ";
    for (auto j = 0; j < size; j++)
    {
      cerr << LL[j] << " ";
    }
    cerr << (ok(LL) ? "true" : "false") << endl;
  }
}
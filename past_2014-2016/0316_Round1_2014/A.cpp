#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int N, L;
int ans;
int outp;
bool changed[50];
string flow_m[160];
string flow[160];
string need[160];

void change(int n) {
  flow[n] = flow_m[n];
  for (auto i=0; i<L; i++) {
    if (changed[i]) {
      flow[n][i] = ((flow[n][i] == '0') ? '1' : '0');
    }
  }
}

void change_all() {
  for (auto i=0; i<N; i++) {
    change(i);
  }
  sort(flow, flow+N);
}

bool match() {
  for (auto i=0; i<N; i++) {
    if (flow[i] != need[i]) return false;
  }
  return true;
}

void how_change(int n) { // need[0]がflow_m[n]と離れている割合
  ans = 0;
  for (auto i=0; i<L; i++) {
    if (need[0][i] != flow_m[n][i]) {
      ans++;
      changed[i] = true;
    } else {
      changed[i] = false;
    }
  }
}

void enjoy() {
  sort(need, need+N);
  outp = 9999;
  for (auto i=0; i<N; i++) {
    how_change(i);
    change_all();
    if (match()) {
      outp = min(outp, ans);
    }
  }
}

int main() {
  int T;
  cin >> T;
  for (auto i=1; i<=T; i++) {
    cin >> N >> L;
    for (auto j=0; j<N; j++) {
      cin >> flow_m[j];
    }
    for (auto j=0; j<N; j++) {
      cin >> need[j];
    }
    enjoy();
    cout << "Case #" << i << ": " 
         << ((outp < 9999) ? to_string(outp) : "NOT POSSIBLE") << endl;
  }
}

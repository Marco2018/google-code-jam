#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main() {
  int T;
  cin >> T;
  for (auto t=1; t<=T; t++) {
    int N;
    cin >> N;
    vector<double> A; // naomi
    vector<double> B; // ken
    for (auto i=0; i<N; i++) {
      double w;
      cin >> w;
      A.push_back(w);
    }
    for (auto i=0; i<N; i++) {
      double w;
      cin >> w;
      B.push_back(w);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    vector<double> A2;
    vector<double> B2;
    copy(A.begin(), A.end(), back_inserter(A2));
    copy(B.begin(), B.end(), back_inserter(B2));
    // Deceitful War
    int win = 0;
    while (!A.empty()) {
      if (A[0] < B[0]) {
        A.erase(A.begin());
        B.erase(B.end()-1);
      } else {
        win++;
        A.erase(A.begin());
        B.erase(B.begin());
      }
    }
    // cerr << "bbb" << endl;
    int win2 = 0;
    while (!A2.empty()) {
      if (A2[A2.size()-1] < B2[B2.size()-1]) {
        A2.erase(A2.end()-1);
        B2.erase(B2.end()-1);
      } else {
        win2++;
        A2.erase(A2.end()-1);
        B2.erase(B2.begin());
      }      
    }
    cout << "Case #" << t << ": " << win << " " << win2 << endl;
  }
}

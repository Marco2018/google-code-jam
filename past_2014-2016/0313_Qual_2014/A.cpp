#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int T;
  cin >> T;
  for (auto t=1; t<=T; t++) {
    int n;
    cin >> n;
    n--;
    int table[4][4];
    for (auto i=0; i<4; i++) {
      for (auto j=0; j<4; j++) {
        cin >> table[i][j];
      }
    }
    bool choose[2][20];
    fill(&choose[0][0], &choose[0][0]+40, false);
    for (auto j=0; j<4; j++) {
      choose[0][table[n][j]] = true;
    }
    cin >> n;
    n--;
    for (auto i=0; i<4; i++) {
      for (auto j=0; j<4; j++) {
        cin >> table[i][j];
      }
    }
    for (auto j=0; j<4; j++) {
      choose[1][table[n][j]] = true;
    }
    int count = 0;
    int x = 0;
    for (auto i=1; i<=16; i++) {
      if (choose[0][i]) cerr << "0 " << i << endl;
      if (choose[1][i]) cerr << "1 " << i << endl;
      if (choose[0][i] && choose[1][i]) {
        count++;
        x = i;
      }
    }
    cout << "Case #" << t << ": ";
    if (count > 1) {
      cout << "Bad magician!" << endl;
    } else if (count < 1) {
      cout << "Volunteer cheated!" << endl;      
    } else {
      cout << x << endl;
    }
  }
}

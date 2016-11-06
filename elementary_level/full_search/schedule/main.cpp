#include <iostream>
using namespace std;
const int N = 5;
const int s[5] = {1, 2, 4, 6, 8};
const int t[5] = {3, 5, 7, 9, 10};

typedef pair<int, int> P;

int main() {
  P itv[N];
  for(int i=0; i<N; i++) {
    itv[i].first = t[i];
    itv[i].second = s[i];
  }

  int ans = 0;
  int t = 0;
  for(int i=0; i<N; i++) {
    if(t < itv[i].second) {
      ans++;
      t = itv[i].first;
    }
  }

  cout << ans << endl;
}

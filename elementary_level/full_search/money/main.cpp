#include <iostream>
using namespace std;
const int N = 6;
const int C[N] = {3, 2, 1, 3, 0, 2};
const int V[N] = {1, 5, 10, 50, 100, 500};
int pay = 620;

int main() {
  int ans = 0;
  int i = N;
  for(int i = N-1; 0 <= i; i--) {
    int t = min(pay/V[i], C[i]);
    if(t != 0) {
      pay -= t * V[i];
      ans += t;
    }
  }

  if (pay > 0) cout << "FALSE" << endl;
  else cout << ans << endl;
}

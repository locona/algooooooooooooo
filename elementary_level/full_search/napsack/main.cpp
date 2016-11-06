#include <iostream>
using namespace std;
const int N = 4;
const int W = 5;
int w[N] = {2, 1, 3, 2};
int v[N] = {3, 2, 4, 2};
int dp[N+1][W+1];

int rec(int i, int j) {
  // if(dp[i][j] >= 0) {
    // return dp[i][j];
  // }
  int res;
  if(i==N) {
    res = 0;
  } else if(j < w[i]) {
    res = rec(i+1, j);
  } else {
    res = max(rec(i + 1, j), rec(i + 1, j - w[i]) + v[i]);
  }
  dp[i][j] = res;
  return res;
}

int main() {
  memset(dp, -1, sizeof(dp));
  printf("%d \n", rec(0, W));

}

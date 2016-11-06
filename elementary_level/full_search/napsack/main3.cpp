#include <iostream>
using namespace std;
const int MAX_N = 100;
const int MAX_W = 100;
const int N = 4;
const int W = 5;
int w[N] = {2, 1, 3, 2};
int v[N] = {3, 2, 4, 2};
int dp[MAX_N][MAX_W];

int main() {
  for(int i=N-1; 0<=i; i--) {
    for(int j=0; j<=W; j++) {
      if(j < w[i]) {
        dp[i][j] = dp[i+1][j];
      } else {
        dp[i][j] = max(dp[i+1][j], dp[i+1][j-w[i]] + v[i]);
      }
    }
  }

  printf("%d ", dp[0][W]);
}




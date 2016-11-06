#include <iostream>
using namespace std;

const int N = 4;
const int M = 4;
const int MAX_N = 100;
const int MAX_M = 100;
int dp[MAX_N][MAX_M];
char a[N] = {'a', 'b', 'c', 'd'};
char b[N] = {'b', 'e', 'c', 'd'};


int main() {
  for(int i=0; i<N; i++) {
    for(int j=0; j<M; j++) {
      if(a[i] == b[j]) dp[i+1][j+1] = dp[i][j] + 1;
      else dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
    }
  }

  printf("%d\n", dp[N][M]);
  for(int i=0; i<=N; i++) {
    for(int j=0; j<=M; j++) {
      printf("%d ", dp[i][j]);
    }
    printf("\n");
  }
}

#include <iostream>
using namespace std;
const int N = 4;
const int W = 5;
int w[N] = {2, 1, 3, 2};
int v[N] = {3, 2, 4, 2};

int rec(int i, int j) {
  int res;
  if(i==N) {
    res = 0;
  } else if(j < w[i]) {
    res = rec(i+1, j);
  } else {
    res = max(rec(i + 1, j), rec(i + 1, j - w[i]) + v[i]);
  }
  return res;
}

int main() {
  printf("%d \n", rec(0, W));
}

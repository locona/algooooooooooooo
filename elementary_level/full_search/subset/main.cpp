#include <iostream>
using namespace std;
const int n = 4;
const int a[n] = {1, 2, 4, 7};
const int k = 13;

bool dfs(int i, int sum);

int main() {

  if(dfs(0, 0)) cout << "TRUE";
  else cout << "FALSE";
}


bool dfs(int i, int sum) {
  if(i==n) return sum == k;
  if(dfs(i+1, sum)) return true;
  if(dfs(i+1, sum+a[i])) return true;
  return false;
}

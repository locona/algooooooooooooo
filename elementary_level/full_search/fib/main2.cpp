#include <iostream>
using namespace std;
const int N = 40;
long int memo[N+1];

long int fib(int n) {
  if(n <= 1) return n;
  if(memo[n] != 0) return memo[n];
  return memo[n] = fib(n-1) + fib(n-2);
}

int main() {
  cout << fib(N);
}

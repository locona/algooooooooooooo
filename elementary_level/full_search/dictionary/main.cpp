#include <iostream>
#include <stack>
using namespace std;
const int N = 6;
int S[N] = {'A', 'C', 'D', 'B', 'C', 'B'};

int main() {
  int s=0, t=N-1;
  int index = 0;
  while(s <= t) {
    bool left = false;
    for(int i=0; s + i <= t; i++) {
      if(S[s+i] < S[t-i]) {
        left = true;
        break;
      } else if(S[s+i] > S[t-i]) {
        left = false;
        break;
      }
    }

    if(left) putchar(S[s++]);
    else putchar(S[t--]);
  }
}

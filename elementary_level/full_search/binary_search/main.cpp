#include <iostream>
using namespace std;
const int N = 5;
int A[N] = {1, 2, 3, 4, 5};
/*
  sort済みの配列から,任意の数値の探索
  1. idx: mid から検索
  2. true: 返す
     false: mid と targetを比較
     * greater(target): left = mid + 1;
     * less(target): right = mid -1;
*/

bool binary_search(int n) {
  int left = 0, right = N;
  while(left < right) {
    int mid = (right + left) / 2;
    printf("%d ", mid);
    if(A[mid] == n) return true;
    else if (A[mid] < n) left = mid + 1;
    else right = mid;
  }

  return false;
}

int main() {
  cout << binary_search(2) << endl;

}

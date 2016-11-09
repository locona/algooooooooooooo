#include <iostream>
using namespace std;
const int SIZE = 20;

typedef int value_type;

int med3(int x, int y, int z) {
  if (x < y) {
    if(y < z) return y; else if(z < x) return x; else return z;
  } else {
    if (z < y) return y; else if(x < z) return x; else return z;
  }
}

void quick_sort(int list[], int left, int right) {
  if(left < right) {
    int i = left, j = right;
    int tmp, pivot = med3(list[i], list[i + (j - 1) / 2], list[j]);
    while(1) {
      while(list[i] < pivot) i++;
      while(list[j] > pivot) j--;
      if(i >= j) break;
      swap(list[i], list[j]);
      i++;
      j--;
    }
    quick_sort(list, left, i-1);
    quick_sort(list, j+1, right);
  }
}

int main() {
  int data[SIZE]= {99,73,20,32,34,5,64,97,25,12,83,9,21,40,3,44,69,15,58,75};
  quick_sort(data, 0, SIZE);

  for(int i=0; i<SIZE; i++) {
    printf("%d ", data[i]);
  }

}

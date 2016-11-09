#include <iostream>
using namespace std;
const int SIZE = 20;

int set_mid_as_pivot(int left, int mid, int right) {
  // ピボットの値を最小値, 最大値を避けるために真ん中の値を設定
  if (left < mid) {
    if(mid < right) return mid; else if(right < left) return left; else return right;
  } else {
    if (right < mid) return mid; else if(left < right) return left; else return right;
  }
}

void quick_sort(int list[], int left, int right) {
  if(left < right) {
    int l = left, r = right, mid = l + (r - 1) / 2;
    int pivot = set_mid_as_pivot(list[l], list[mid], list[r]);
    while(1) {
      // 左右の値を交換のため、ピボットをそれぞれ超える値を探索
      // もし片方がみつからなければ、ピボットを再定義
      while(list[l] < pivot) l++;
      while(list[r] > pivot) r--;
      if(l >= r) break;
      swap(list[l++], list[r--]);
    }

    // 最初にpivotからの大小を区分しているため、次のソートが成り立つ
    quick_sort(list, left, l-1); // 左の区分野中でソート
    quick_sort(list, r+1, right);// 右の区分の中でソート
  }
}

int main() {
  int data[SIZE]= {99,73,20,32,34,5,64,97,25,12,83,9,21,40,3,44,69,15,58,75};
  quick_sort(data, 0, SIZE);

  for(int i=0; i<SIZE; i++) {
    printf("%d ", data[i]);
  }

}

#include <iostream>
using namespace std;
int cnt = 0;
const int N = 10;
const int M = 12;
int field[N][M] = {
// 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
  {1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
  {0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1},
  {0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
  {0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0},
  {1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0},
  {0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0},
  {0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0}
};

bool dfs(int x, int y);

int main() {
  for(int i=0; i<N; i++) {
    for(int j=0; j<M; j++) {
      if(field[i][j] == 1) {
      dfs(i,j);
      cnt++;
      }
    }
  }
  cout << cnt << endl;
}

bool dfs(int x, int y) {
  field[x][y] = 0;
  for(int dx = -1; dx <= 1; dx++) {
    for(int dy = -1; dy <= 1; dy++) {
      int nx = x + dx;
      int ny = y + dy;
      if((0 <= nx && nx < 10) && (0 <= ny && ny < M) && field[nx][ny] == 1) dfs(nx, ny);
    }
  }
  return 0;
}

#include <iostream>
#include <queue>
using namespace std;
int cnt = 0;
int INF = -1;
const int N = 10;
const int M = 10;
int sx = 0, sy = 1;
int gx = 9, gy = 8;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int d[N][M];
int maze[N][M] = {
// 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
  {8,10, 8, 8, 8, 8, 8, 8, 0, 8},
  {0, 0, 0, 0, 0, 0, 8, 0, 0, 8},
  {0, 8, 0, 8, 8, 0, 8, 8, 0, 8},
  {0, 8, 0, 0, 0, 0, 0, 0, 0, 0},
  {8, 8, 0, 8, 8, 0, 8, 8, 0, 8},
  {0, 0, 0, 0, 8, 0, 0, 0, 0, 8},
  {0, 8, 8, 8, 8, 8, 8, 8, 0, 8},
  {0, 0, 0, 0, 8, 0, 0, 0, 0, 0},
  {0, 8, 8, 8, 8, 0, 8, 8, 8, 0},
  {0, 0, 0, 0, 8, 0, 0, 0,10, 8}
};

typedef pair<int, int> P;

int bfs() {
  queue<P> que;

  // init
  for(int i=0; i<N; i++)
    for(int j=0; j<M; j++)
      d[i][j] = INF;

  que.push(P(sx, sy)); // start
  d[sx][sy] = 0;

  while(que.size()) {
    P p = que.front();
    que.pop();

    if(p.first == gx && p.second == gy) break;

    for(int i=0; i<4; i++) {
      int nx = p.first + dx[i];
      int ny = p.second + dy[i];

      if(0 <= nx && nx < N && 0 <= ny && ny < M && maze[nx][ny] != 8 && d[nx][ny] == INF) {
        que.push(P(nx, ny));
        d[nx][ny] = d[p.first][p.second] + 1;
      }
    }
  }

  for(int i=0; i<N; i++) {
    for(int j=0; j<M; j++) {
      printf("%d  ", d[i][j]);
    }
    cout << endl;
  }
  return d[gx][gy];
}

int main() {
  cout << bfs() << endl;
}


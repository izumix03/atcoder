#include <queue>
#include <iostream>

// https://atcoder.jp/contests/abc007/tasks/abc007_3
using namespace std;

int maze[50][50];
int steps[50][50];

int maxY, maxX;
int sy, sx;
int gy, gx;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

typedef pair<int, int> P;

int INF = 100000000;

void bfs() {
  queue<P> que;

  que.push(P(sy,sx));
  steps[sy][sx] = 0;

  while (!que.empty()) {
    P p = que.front();
    que.pop();

    if (p.first == gy && p.second == gx) {
      printf("%d\n", steps[gy][gx]);
      return;
    }

    for (int i = 0; i < 4; i++) {
      int nextY = p.first + dx[i];
      int nextX = p.second + dy[i];

      if (0 <= nextY && nextY < maxY
          && 0 <= nextX && nextX < maxX
          && maze[nextY][nextX] != 0
          && steps[nextY][nextX] == INF) {
        que.push(P(nextY, nextX));
        steps[nextY][nextX] = steps[p.first][p.second] + 1;
      }
    }
  }
}

int main() {
  cin >> maxY >> maxX;

  cin >> sx >> sy;
  sy -= 1;
  sx -= 1;

  cin >> gy >> gx;
  gy -= 1;
  gx -= 1;

  char c[50];

  for (int i = 0; i < maxY; i++) {
    cin >> c;
    for (int j = 0; j < maxX; j++) {
      if (c[j] == '#') {
        maze[i][j] = 0;
      } else {
        maze[i][j] = 1;
      }
      steps[i][j] = INF;
    }
  }

  bfs();
  return 0;
}

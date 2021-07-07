#include <vector>

using namespace std;

void bfs();

int main() {
  bfs();
  return 0;
}

// N × Mの迷路
//
typedef pair<int, int> P;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

#include <queue>

void bfs() {

  // キューを定義
  queue<P> que;
  int N = 10;
  int M = 10;

  char maze[10][10] = {
      {'#', 'S', '#', '#', '#', '#', '#', '#', '.', '#'},
      {'.', '.', '.', '.', '.', '.', '#', '.', '.', '#'},
      {'.', '#', '.', '#', '#', '.', '#', '#', '.', '#'},
      {'.', '#', '.', '.', '.', '.', '.', '.', '.', '.'},
      {'#', '#', '.', '#', '#', '.', '#', '#', '#', '#'},
      {'.', '.', '.', '.', '#', '.', '.', '.', '.', '#'},
      {'.', '#', '#', '#', '#', '#', '#', '#', '.', '#'},
      {'.', '.', '.', '.', '#', '.', '.', '.', '.', '.'},
      {'.', '#', '#', '#', '#', '.', '#', '#', '#', '.'},
      {'.', '.', '.', '.', '#', '.', '.', '.', 'G', '#'}
  };

  int d[10][10];
  const int INF = 10000000;
  int sx = 0;
  int sy = 1;

  int gx = 9;
  int gy = 8;

  // 初期化
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      d[i][j] = INF;
    }
  }

  // スタート地点
  que.push(P(sx, sy));
  d[sx][sy] = 0;

  while (!que.empty()) {
    // 先頭取り出し
    P p = que.front();
    que.pop();

    printf("%d, %d\n", p.first, p.second);

    if (p.first == gx && p.second == gy) {
      printf("%d\n", d[gx][gy]);
    }

    for (int i = 0; i < 4; i++) {

      int nx = p.first + dx[i];
      int ny = p.second + dy[i];

      if (0 <= nx && nx < N && 0 <= ny && ny < M
          && maze[nx][ny] != '#'
          && d[nx][ny] == INF
          ) {
        que.push(P(nx, ny));
        d[nx][ny] = d[p.first][p.second] + 1;
      }
    }
  }
}
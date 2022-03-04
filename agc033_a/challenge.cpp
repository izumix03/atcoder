#include <iostream>
#include <queue>

using namespace std;

#define MAX_N 1000
#define INF 10000000

char maze[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];
/**
 * https://atcoder.jp/contests/agc033/tasks/agc033_a
 * 縦 N、横 M
 * A11 ~ AHW
 * すべてのマスが黒になるまで繰り返し
 *  辺を共有して隣接するマスの中に、
 * 何回の操作になるか？
 * 少なくとも1つは黒
 */

int N, M;
typedef pair<int, int> P;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

queue<P> q;

void input() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> maze[i][j];
      if (maze[i][j] == '#') {
        q.push(P(i, j));
        visited[i][j] = 0;
      } else {
        visited[i][j] = INF;
      }
    }
  }
}

void solve() {
  int maxN = 0;
  while (!q.empty()) {
    P p = q.front();q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = p.first + dy[i];
      int nx = p.second + dx[i];

      if (0 <= ny && ny < N
          && 0 <= nx && nx < M
          && maze[ny][nx] == '.'
          && visited[ny][nx] == INF) {
        q.push(P(ny, nx));
        visited[ny][nx] = visited[p.first][p.second] + 1;
        maxN = max(maxN, visited[p.first][p.second] + 1);
      }
    }
  }

  cout << maxN << endl;
}

void main() {
  input();
  solve();
  return 0;
}
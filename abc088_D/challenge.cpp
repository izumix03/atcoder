#include <iostream>
#include <queue>

using namespace std;
#define MAX_N 50

typedef pair<int, int> P;
#define INF 1000000

int N, M;

char maze[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int cnt = 0;

/**
 * https://atcoder.jp/contests/abc088/tasks/abc088_d
 * 縦 N、横 M
 * (1, 1) からスタート
 * 上下左右のみ
 * 白いマスだけ通れる .
 * 黒に変える数が点数 #
 */
void input() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> maze[i][j];
      if (maze[i][j] == '#') cnt++;
      visited[i][j] = INF;
    }
  }
}

void solve() {
  queue<P> q;
  q.push(P(0, 0));
  visited[0][0] = 1; // 黒じゃないので

  while (!q.empty()) {
    P p = q.front();
    q.pop();

    if (p.first == N - 1 && p.second == M - 1) {
      cout << N * M - visited[p.first][p.second] - cnt << endl;
      return;
    }

    for (int i = 0; i < 4; i++) {
      int ny = p.first + dy[i];
      int nx = p.second + dx[i];

      if (0 <= ny && ny < N
          && 0 <= nx && nx < M
          && maze[ny][nx] != '#'
          && visited[ny][nx] == INF) {
        q.push(P(ny, nx));
        visited[ny][nx] = visited[p.first][p.second] + 1;
      }
    }
  }
  cout << -1 << endl;
}

void main() {
  input();
  solve();
  return 0;
}
#include <iostream>
#include <queue>

using namespace std;
#define MAX_N 50

typedef pair<int, int> P;
#define INF 1000000

int H, W;

char maze[MAX_N][MAX_N];
int steps[MAX_N][MAX_N];

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int cnt = 0;

/**
 * https://atcoder.jp/contests/abc088/tasks/abc088_d
 * 縦 H、横 W
 * (1, 1) からスタート
 * 上下左右のみ
 * 白いマスだけ通れる .
 * 黒に変える数が点数 #
 */
void input() {
  cin >> H >> W;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> maze[i][j];
      if (maze[i][j] == '#') cnt++;
      steps[i][j] = INF;
    }
  }
}

void solve() {
  queue<P> q;
  q.push(P(0, 0));
  steps[0][0] = 1; // 黒じゃないので

  while (!q.empty()) {
    P p = q.front();
    q.pop();

    if (p.first == H - 1 && p.second == W - 1) {
      cout << H * W - steps[p.first][p.second] - cnt << endl;
      return;
    }

    for (int i = 0; i < 4; i++) {
      int ny = p.first + dy[i];
      int nx = p.second + dx[i];

      if (0 <= ny && ny < H
          && 0 <= nx && nx < W
          && maze[ny][nx] != '#'
          && steps[ny][nx] == INF) {
        q.push(P(ny, nx));
        steps[ny][nx] = steps[p.first][p.second] + 1;
      }
    }
  }
  cout << -1 << endl;
}

int main() {
  input();
  solve();
  return 0;
}
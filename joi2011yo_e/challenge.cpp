#include <iostream>
#include <queue>

using namespace std;

/**
 * https://atcoder.jp/contests/joi2011yo/tasks/joi2011yo_e
 * 巣 / チーム工場 / 障害物 / 空き地
 * ねずみ は 巣 から出発、全部のチーズ工場を訪れる
 * 硬さ 1 ~ N
 * 体力は最初 1
 *  チーム1つで1増える、自分の体力より硬いものは食べられない
 * 東西南北に1分で移動、障害物は入れない
 * チーズ工場で食べない、ということもできる
 * 最短時間を求めよ、食べる時間は無視
 */

// 1 <= H <= 1000
// 1 <= W <= 1000
// 1 <= N <= 9

#define MAX_N 1000
#define INF 1000000

typedef pair<int, int> P;

int H, W, N;

// s = 巣、x = 障害、. = 空き地、1-9 = チーズ工場
char map[MAX_N][MAX_N];
int steps[MAX_N][MAX_N];

void input() {
  cin >> H >> W >> N;

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> map[i][j];
      steps[i][j] = INF;
    }
  }
}

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

P goNext(int y, int x, int I) {
  queue<P> q;

  bool done[MAX_N][MAX_N] = {false};

  q.push(P(y, x));
  if (steps[y][x] == INF) steps[y][x] = 0;

  while (!q.empty()) {
    P p = q.front();
    q.pop();

    if (map[p.first][p.second] == '0' + I) {
      return p;
    }

    for (int i = 0; i < 4; i++) {
      int ny = p.first + dy[i];
      int nx = p.second + dx[i];

      if (0 <= ny && ny < H
          && 0 <= nx && nx < W
          && map[ny][nx] != 'X'
          && !done[ny][nx]) {
        q.push(P(ny, nx));
        steps[ny][nx] = steps[p.first][p.second] + 1;
        done[ny][nx] = true;
      }
    }
  }
}

void solve() {

  int y = -1, x;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (map[i][j] == 'S') {
        y = i;
        x = j;
        break;
      }
    }
    if (y != -1) break;
  }
  P p(y, x);
  for (int i = 1; i <= N; i++) {
    p = goNext(p.first, p.second, i);
  }

  cout << steps[p.first][p.second] << endl;
}

int main() {
  input();
  solve();
  return 0;
}

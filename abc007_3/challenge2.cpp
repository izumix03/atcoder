#include <iostream>
#include <queue>

using namespace std;
#define MAX_N 50
#define INF 100000000

int w, h, sy, sx, gy, gx;
int maze[MAX_N][MAX_N];
int step[MAX_N][MAX_N];

typedef pair<int, int> P;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

void solve() {
  queue<P> q;
  q.push(P(sy, sx));
  step[sy][sx] = 0;

  while (!q.empty()) {
    P p = q.front();
    q.pop();

    if (p.first == gy && p.second == gx) {
      cout << step[gy][gx] << endl;
    }

    for (int i = 0; i < 4; i++) {
      int ny = p.first + dy[i];
      int nx = p.second + dx[i];

      if (0 <= ny && ny < h
          && 0 <= nx && nx < w
          && maze[ny][nx] != 0
          && step[ny][nx] == INF) {
        q.push(P(ny, nx));
        step[ny][nx] = step[p.first][p.second] + 1;
      }
    }
  }
}

void input() {
  cin >> h >> w;
  cin >> sy >> sx;
  sy--;sx--;
  cin >> gy >> gx;
  gy--;gx--;

  char c[MAX_N];

  for (int i = 0; i < h; i++) {
    cin >> c;
    for (int j = 0; j < w; j++) {
      maze[i][j] = c[j] == '#' ? 0 : 1;
      step[i][j] = INF;
    }
  }
}

void main() {
  input();
  solve();
  return 0;
}
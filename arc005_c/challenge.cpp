#include <iostream>
#include <queue>

using namespace std;

#define MAX_N 500
#define INF 10000000

char maze[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];
/**
 * https://atcoder.jp/contests/arc005/tasks/arc005_3
 * 縦 N、横 M
 * 2回まで無視できる
 * いけるなら YES だめなら NO
 * s: 家
 * g: 魚
 * .: 道
 * #: 塀
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
      if (maze[i][j] == 's') {
        q.push(P(i, j));
      }
      visited[i][j] = -1;
    }
  }
}

void solve() {
  while (!q.empty()) {
    P p = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = p.first + dy[i];
      int nx = p.second + dx[i];

      if (maze[ny][nx] == 'g') {
        cout << "YES" << endl;
        return;
      }

      if (0 <= ny && ny < N
          && 0 <= nx && nx < M
          && (visited[p.first][p.second] < 2 || maze[ny][nx] == '.')
        ) {
        int val = maze[ny][nx] == '#' ? 1 : 0;
        int step = max(visited[p.first][p.second], 0) + val;
        if (visited[ny][nx] == -1 || visited[ny][nx] > step) {
          q.push(P(ny, nx));
          visited[ny][nx] = step;
        }
      }
    }
  }

  cout << "NO" << endl;
}

void main() {
  input();
  solve();
  return 0;
}
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> P;

int INF = -1;

int solve(const vector<string> &maze, int sy, int sx, vector<int> moveY, vector<int> moveX) {
  queue<P> q;
  int maxCount = 0;

  int maxX = int(maze[0].size());
  int maxY = int(maze.size());

  int steps[50][50];
  for (int i = 0; i < maxY; i++) {
    for (int j = 0; j < maxX; j++) {
      steps[i][j] = INF;
    }
  }

  q.push(P(sy, sx));
  steps[sy][sx] = 0;

  while (!q.empty()) {
    P p = q.front();
    q.pop();

    // goal
    for (int i = 0; i < moveX.size(); i++) {
      int nextX = p.second + moveX.at(i);
      int nextY = p.first + moveY.at(i);

      if (0 <= nextX && nextX < maxX &&
          0 <= nextY && nextY < maxY &&
          maze[nextY][nextX] != 'X' &&
          steps[nextY][nextX] == INF) {
        q.push(P(nextY, nextX));
        maxCount = max(
            steps[nextY][nextX] = steps[p.first][p.second] + 1,
            maxCount
        );
      }
    }
  }

  for (int i = 0; i < maxY; i++) {
    for (int j = 0; j < maxX; j++) {
      if (maze[i][j] == '.' && steps[i][j] == INF) {
        return -1;
      }
    }
  }

  return maxCount;
}

/**
 * 通れるところは '.'
 * 通れないとこは 'X'
 *
 * 初期は startRow startCol
 * 動き方は moveRow moveCol
 *
 * できるだけ異動距離が長くなるように 出口 を '.' 上に決める
 * 最大超約数を返せ
 * @return
 */
void main() {
  cout << solve({"...",
                 "...",
                 "..."},
                0, 1,
                {1, 0, -1, 0},
                {0, 1, 0, -1}) << endl; // 3

  cout << solve({"...",
                 "...",
                 "..."},
                0, 1,
                {1, 0, -1, 0, 1, 1, -1, -1},
                {0, 1, 0, -1, 1, -1, 1, -1}) << endl; // 2

  cout << solve({"X.X",
                 "...",
                 "XXX",
                 "X.X"},
                0, 1,
                {1, 0, -1, 0},
                {0, 1, 0, -1}) << endl; // -1

  cout << solve({".......",
                 "X.X.X..",
                 "XXX...X",
                 "....X..",
                 "X....X.",
                 "......."},
                5, 0,
                {1, 0, -1, 0, -2, 1},
                {0, -1, 0, 1, 3, 0}) << endl; // 7

  cout << solve({"......."},
                0, 0,
                {1, 0, 1, 0, 1, 0},
                {0, 1, 0, 1, 0, 1}) << endl; // 6

  cout << solve({"..X.X.X.X.X.X."},
                0, 0,
                {-2, 0, -2, 0},
                {0, 2, 0, -2}) << endl; // -1
}
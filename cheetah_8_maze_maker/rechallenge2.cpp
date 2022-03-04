#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> P;

int INF = -1;

int solve(const vector<string> &maze, // [Row][Col]
          int startRow,
          int startCol,
          vector<int> moveRow,
          vector<int> moveCol) {
  // 最大のX、Yを取得する
  int maxY = int(maze.size());
  int maxX = int(maze[0].size());

  // 移動した回を記録する,最大個数は50,50,Y -> X
  int steps[50][50];

  //  初期化する
  for (int y = 0; y < maxY; y++) {
    for (int x = 0; x < maxX; x++) {
      steps[y][x] = INF;
    }
  }

  // 有効地点のキューを使って幅優先
  queue<P> q;

  // 初期位置を設定
  q.push(P(startRow, startCol));
  steps[startRow][startCol] = 0;

  // キューに詰めなくなるまで処理
  while (!q.empty()) {
    P prev = q.front();
    q.pop();

    for (int i = 0; i < moveRow.size(); i++) {
      int nextX = prev.second + moveCol[i];
      int nextY = prev.first + moveRow[i];

      if (nextX >= 0 && nextY >= 0
          && nextX < maxX && nextY < maxY
          // maze[y][x] 考慮できていなかった
          && maze[nextY][nextX] != 'X'
          && steps[nextY][nextX] == INF) {
        // firstとsecondが混ざった
        steps[nextY][nextX] = steps[prev.first][prev.second] + 1;
        q.push(P(nextY, nextX));
      }
    }
  }

  // 全部の位置に行けているかチェック
  int maxCnt = 0;
  for (int y = 0; y < maxY; y++) {
    for (int x = 0; x < maxX; x++) {
      // maze[y][x] == '.'  考慮できていなかった
      if (maze[y][x] == '.' && steps[y][x] == INF) return INF;
      maxCnt = max(maxCnt, steps[y][x]);
    }
  }

  return maxCnt;
}

/**
 * 通れるところは '.'
 * 通れないとこは 'X'
 *
 * 初期は startRow startCol
 * 動き方は moveRow moveCol
 *
 * できるだけ異動距離が長くなるように 出口 を '.' 上に決める
 * 最大移動数を返せ
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
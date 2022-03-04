#include <string>
#include <iostream>

using namespace std;
typedef pair<int, int> P;

// n * n のチェス
// 'L' は1回の動きで、'K' ⇛ 'X' or 'k' ⇛ 'L'
// キングナイト = 全方向に1マス(1, 1 or 1, 0など) or L字型に動く(2, 1)
// start, end
// numMove回で移動する方法の数はいくつ？
// memo: あれ？これ start が 0, 0 以外でもいける？と思いきや固定だった

int vx[] = {1, -1, 0, 0, 1, -1, 1, -1, 2, 1, -1, -2, -2, -1, 1, 2};
int vy[] = {0, 0, 1, -1, 1, 1, -1, -1, -1, -2, -2, -1, 1, 2, 2, 1};


long long solve(int size, P start, P end, int numMove) {
  // x, y, numMove
  long long ways[100][100][55] = {0};
  int x, y, i, j;

  ways[start.second][start.first][0] = 1;

  for (i = 1; i <= numMove; i++) {
    for (x = 0; x < size; x++) {
      for (y = 0; y < size; y++) {
        for (j = 0; j < 16; j++) {
          int nextX = x + vx[j];
          int nextY = y + vy[j];

          if (nextX < 0 || nextY < 0 || nextX >= size || nextY >= size) continue;

          ways[nextY][nextX][i] += ways[y][x][i - 1];
        }
      }
    }
  }
  return ways[end.second][end.first][numMove];
}

void main() {
  cout << solve(3, P{0, 0}, P{1, 0}, 1) << endl; // 1
  cout << solve(3, P{0, 0}, P{1, 2}, 1) << endl; // 1
  cout << solve(3, P{0, 0}, P{2, 2}, 1) << endl; // 0
  cout << solve(3, P{0, 0}, P{0, 0}, 2) << endl; // 5
  cout << solve(100, P{0, 0}, P{0, 99}, 50) << endl; // 243097320072600

  return 0;
}
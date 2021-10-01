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
int main() {
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
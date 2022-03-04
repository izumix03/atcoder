#include <iostream>

using namespace std;

bool grid[100][100] = {false};
int vx[] = {0, 0, 1, -1};
int vy[] = {1, -1, 0, 0};

double saiki(int n, double rate[], int x, int y) {
  if (grid[x][y]) return 0.0;
  if (n == 0) return 1.0;

  double r = 0;
  grid[x][y] = true;
  for (int i = 0; i < 4; i++) {
    r += rate[i] * saiki(n-1, rate, x + vx[i], y + vy[i]);
  }

  grid[x][y] = false;
  return r;
}

// 2日目に合格！！
// ロボットがランダムに n ステップ動く
// 方向は 4つ(north, south, east, west)
// それぞれの方向に進む％がある
// 同じ場所を通るのは失敗
// 成功する確率 double で返そう
double solve(int n, int east, int west, int south, int north) {
  double rate[] = {east / 100.0, west / 100.0, south/ 100.0, north/ 100.0};
  return saiki(n, rate, 50, 50);
}

void main() {
  cout << solve(1, 25, 25, 25, 25) << endl; // 1.0
  cout << solve(2, 25, 25, 25, 25) << endl; // 0.75
  cout << solve(7, 50, 0, 0, 50) << endl; // 1.0
  cout << solve(14, 50, 50, 0, 0) << endl; // 1.220703125E-4
  cout << solve(14, 25, 25, 25, 25) << endl; // 0.008845493197441101
}
#include <iostream>
#include <vector>

using namespace std;

/**
 * 数学
 * 最小何個の円をまたいで目的地にたどり着くか問題
 *
 * circles country = 円で区切られた区域がある国
 * 区域の協会は交差せず、接してもいない
 * 区域は含まれることがある
 *
 * 区域 i の中心は (x[i], y[i]), 半径 R[i]
 * 現在地は (x1, y1), (x2, y2) に向かう
 * ※境界線上にはない
 *
 * 最小の境界数を返す
 *
 * x: 1 <= length <= 50
 * x, y, R: 同じ要素数を持つ配列
 * x, y: -1000 <= value <= 1000
 * R: 1 <= length <= 1000
 */
bool inside(int x1, int y1, int x2, int y2, int r) {
  return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) <= r * r;
}

int solve(vector<int> x, vector<int> y, vector<int> R, int x1, int y1, int x2, int y2) {
  int num = 0;

  for (int i = 0; i < x.size(); i++) {
    if (inside(x[i], y[i], x1, y1, R[i]) != inside(x[i], y[i], x2, y2, R[i])) num++;
  }

  return num;
}

void main() {
  cout << solve({0}, {0}, {2}, -5, 1, 5, 1) << endl; // 0
  cout << solve({0, -6, 6}, {0, 1, 2}, {2, 2, 2}, -5, 1, 5, 1) << endl; // 2
  cout << solve({1, -3, 2, 5, -4, 12, 12}, {1, -1, 2, 5, 5, 1, 1}, {8, 1, 2, 1, 1, 1, 2}, -5, 1, 12, 1) << endl; // 3
  cout << solve({-3, 2, 2, 0, -4, 12, 12, 12}, {-1, 2, 3, 1, 5, 1, 1, 1}, {1, 3, 1, 7, 1, 1, 2, 3}, 2, 3, 13, 2)
       << endl; // 5

  return 0;
}
#include <iostream>
#include <cstdlib>
using namespace std;

bool solve(
  int pt,
  int px,
  int py,
  int t,
  int x,
  int y
) {
  int dt = t - pt;
  int dx = x - px;
  int dy = y - py;

  if (abs(dx) + abs(dy) > dt) return false;
  if (abs(dx + dy) % 2 != dt % 2) return false;

  return true;
}

/**
 * (0, 0) から出発
 * 1 <= N <= 10^5 に (xi, yi) が与えられる
 * 動き方は x か y かのどちらかに 1 だけ動く
 * @return
 */
int main() {
  int N;
  cin >> N;

  int px = 0, py = 0;
  int pt = 0;

  int t[N], x[N], y[N];
  for (int i = 0; i < N; i++) {
    cin >> t[i] >> x[i] >> y[i];
  }

  for (int i = 0; i < N; i++) {
    if (solve(pt, px, py, t[i], x[i], y[i])) {
      px = x[i];
      py = y[i];
      pt = t[i];
    } else {
      cout << "No" << endl;
      return 0;
    }
  }
//  for (int i = 0; i < N; i++) {
//    int t;
//    int x;
//    int y;
//
//    cin >> t >> x >> y;
//
//    if (solve(pt, px, py, t, x, y)) {
//      px = x;
//      py = y;
//      pt = t;
//    } else {
//      cout << "No" << endl;
//      return 0;
//    }
//  }

  cout << "Yes" << endl;
  return 0;
}


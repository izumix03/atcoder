#include <vector>
#include <iostream>

using namespace std;

// https://atcoder.jp/contests/atc001/tasks/dfs_a
long long h, w;
bool ok = false;
vector<string> c;

void dfs(long long x, long long y) {
  if (x >= w || x < 0) return;
  if (y >= h || y < 0) return;

  if (c[y][x] == '#') return;

  if (c[y][x] == 'g') {
    ok = true;
    return;
  }
  c[y][x] = '#';

  dfs(x + 1, y);
  if (ok) return;

  dfs(x - 1, y);
  if (ok) return;

  dfs(x, y + 1);
  if (ok) return;

  dfs(x, y - 1);
  if (ok) return;
}

void main() {
  cin >> h >> w;

  long long sy = 0, sx = 0;
  c.resize(h);

  for (long long i = 0; i < h; i++) {
    cin >> c[i];

    for (long long j = 0; j < w; j++) {
      if (c[i][j] == 's') {
        sy = i;
        sx = j;
      }
    }
  }
  dfs(sx, sy);

  if (ok) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}

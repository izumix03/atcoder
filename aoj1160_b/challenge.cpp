#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 50

int map[MAX_N][MAX_N], width, height;
bool done[MAX_N][MAX_N];

void walk(int i, int j) {
  if (i < 0 || i >= height || j < 0 || j >= width) {
    return;
  }
  if (map[i][j] == 0 || done[i][j]) return;

  done[i][j] = true;
  walk(i - 1, j - 1);
  walk(i - 1, j );
  walk(i - 1, j + 1);
  walk(i, j - 1);
  walk(i, j + 1);
  walk(i + 1, j - 1);
  walk(i + 1, j);
  walk(i + 1, j + 1);
}

void solve() {
  // 8パターン移動
  int cnt = 0;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (map[i][j] == 1 && !done[i][j]) {
        cnt++;
        walk(i, j);
      }
    }
  }
  cout << cnt << endl;
}

void clear() {
  for (int i = 0; i < MAX_N; i++) {
    for (int j = 0; j < MAX_N; j++) {
      map[i][j] = 0;
      done[i][j] = false;
    }
  }
}

void input() {
  while (true) {
    clear();
    cin >> width >> height;
    if (height == 0) break;

    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        cin >> map[i][j];
      }
    }

    solve();
  }
}

int main() {
  input();
  return 0;
}
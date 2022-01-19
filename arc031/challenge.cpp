#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> input(10, vector<char>(10));
int cnt = 0;

// https://atcoder.jp/contests/arc031/tasks/arc031_2

void dfs(vector<vector<bool>> &checked, int y, int x) {
  if (y < 0 || x < 0 || y >= 10 || x >= 10) return;
  if (input[y][x] == 'x') return;
  if (checked[y][x]) return;

  checked[y][x] = true;

  dfs(checked, y + 1, x);
  dfs(checked, y - 1, x);
  dfs(checked, y, x + 1);
  dfs(checked, y, x - 1);
}

bool check() {
  vector<vector<bool>> checked(10, vector<bool>(10, false));

  int x = -1, y = -1;
  for (int i = 0; i < 10; i++) {
    if (x > 0) break;
    for (int j = 0; j < 10; j++) {
      if (input[i][j] == 'o') {
        y = i;
        x = j;
        break;
      }
    }
  }
  dfs(checked, y, x);

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (input[i][j] == 'o' && !checked[i][j]) {
        return false;
      }
    }
  }

  return true;
}

int main() {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      cin >> input[i][j];
      if (input[i][j] == 'o') cnt++;
    }
  }

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (input[i][j] == 'o') continue;

      input[i][j] = 'o';

      if (check()) {
        cout << "YES" << endl;
        return 0;
      }

      input[i][j] = 'x';
    }
  }
  cout << "NO" << endl;
  return 0;
}

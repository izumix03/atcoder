#include <iostream>

using namespace std;

#define MAX_N 9
#define MAX_M 28

int N, M;

int routes[MAX_M][2];

/**
 * https://atcoder.jp/contests/abc054/tasks/abc054_c
 * 頂点N、線M
 * 1 からスタート
 * 全部1回通るルートが何通りあるか答える
 * 自己ループは含まない
 */
void input() {
  cin >> N >> M;
  int f, s;
  for (int i = 0; i < M; i++) {
    cin >> f >> s;
    routes[i][0] = f;
    routes[i][1] = s;
  }
}

int cnt = 0;
bool visited[MAX_M] = {false};

void solve(int target) {
  visited[target] = true;

  bool allVisited = true;
  for (int i = 1 ; i <= N; i++) {
    if (!visited[i]) {
      allVisited = false;
      break;
    }
  }
  if (allVisited) {
    cnt++;
    visited[target] = false;
    return;
  }

  for (int i = 0; i < M; i++) {
    if (routes[i][0] == target) {
      if (!visited[routes[i][1]]) {
        solve(routes[i][1]);
      }
    }
    if (routes[i][1] == target) {
      if (!visited[routes[i][0]]) {
        solve(routes[i][0]);
      }
    }
  }

  visited[target] = false;
}

int main() {
  input();
  solve(1);
  cout << cnt << endl;
  return 0;
}
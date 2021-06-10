#include <vector>

using namespace std;

void pattern1();

void pattern2();

int main() {
  pattern1();
  pattern2();
  return 0;
}

// 深さ優先探索
bool select(vector<int> a, int index, int sum, int target) {
  printf("%d\n", sum);
  // 全パターン完了していたら判定！
  if (a.size() == index) return sum == target;

  // 使わない場合
  if (select(a, index + 1, sum, target)) return true;

  // 使う場合
  if (select(a, index + 1, sum + a.at(index), target)) return true;

  return false;
}

// 整数a1, a2, ..., an
// いくつか選択、和 = k とできるかどうか
// 1 <= n <= 20
// -10**8 <= ai <= 10**8
// -10**8 <= k <= 10**8
void pattern1() {
  //  int n = 4;
  vector<int> a = {1, 2, 4, 7};
  int k = 13;
  printf("%s", select(a, 0, 0, k) ? "true" : "false");
}

// N × Mの迷路
//
typedef pair<int, int> P;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

#include <queue>

void pattern2() {
  // キューを定義
  queue<P> que;
  int N = 10;
  int M = 10;

  char maze[10][10] = {
      {'#', 'S', '#', '#', '#', '#', '#', '#', '.', '#'},
      {'.', '.', '.', '.', '.', '.', '#', '.', '.', '#'},
      {'.', '#', '.', '#', '#', '.', '#', '#', '.', '#'},
      {'.', '#', '.', '.', '.', '.', '.', '.', '.', '.'},
      {'#', '#', '.', '#', '#', '.', '#', '#', '#', '#'},
      {'.', '.', '.', '.', '#', '.', '.', '.', '.', '#'},
      {'.', '#', '#', '#', '#', '#', '#', '#', '.', '#'},
      {'.', '.', '.', '.', '#', '.', '.', '.', '.', '.'},
      {'.', '#', '#', '#', '#', '.', '#', '#', '#', '.'},
      {'.', '.', '.', '.', '#', '.', '.', '.', 'G', '#'}
  };

  int d[10][10];
  const int INF = 10000000;
  int sx = 0;
  int sy = 1;

  int gx = 9;
  int gy = 8;

  // 初期化
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      d[i][j] = INF;
    }
  }

  // スタート地点
  que.push(P(sx, sy));
  d[sx][sy] = 0;

  while (!que.empty()) {
    // 先頭取り出し
    P p = que.front();
    que.pop();

    printf("%d, %d\n", p.first, p.second);

    if (p.first == gx && p.second == gy) {
      printf("%d\n", d[gx][gy]);
    }

    for (int i = 0; i < 4; i++) {

      int nx = p.first + dx[i];
      int ny = p.second + dy[i];

      if (0 <= nx && nx < N && 0 <= ny && ny < M
          && maze[nx][ny] != '#'
          && d[nx][ny] == INF
          ) {
        que.push(P(nx, ny));
        d[nx][ny] = d[p.first][p.second] + 1;
      }
    }
  }

}
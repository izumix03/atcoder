#include <cstdio>
#include <algorithm>
#include <iostream>
#include <ctime>

using namespace std;

void pattern1();

int main() {
  pattern1();
  return 0;
}

// ■ 動的計画法
// 重さ = wi
// 価値 = vi
// 個数 = n
// 重さの総和が W 以下になるようにして「価値を最大化」
// 1 <= n <= 100
// 1 <= wi, vi <= 100
// 1 <= W <= 10000


// 深さ優先探索
int solve1(int n, int w[4], int v[4], int index, int weight) {
  int value = 0;
  // 全パターン完了していたら判定！
  if (index == n) {
    return value;
  }

  // 使わない
  if (weight < w[index]) {
    return solve1(n, w, v, index + 1, weight);
  }

  value = std::max(
      solve1(n, w, v, index + 1, weight - w[index]) + v[index],
      solve1(n, w, v, index + 1, weight)
  );

  return value;
}

int solve2(int n, int w[], int v[], int index, int weight, int memo[5][100]) {
  if (memo[index][weight] >= 0) {
    return memo[index][weight];
  }

  if (index == n) {
    return memo[index][weight] = 0;
  }

  if (weight < w[index]) {
    return memo[index][weight] = solve2(n, w, v, index + 1, weight, memo);
  }

  return memo[index][weight] = std::max(
      solve2(n, w, v, index + 1, weight - w[index], memo) + v[index],
      solve2(n, w, v, index + 1, weight, memo)
  );
}

int solve3(int n, const int w[], const int v[], int weight, int memo[5][100]) {
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j <= weight; j++) {
      if (j < w[i]) {
        memo[i][j] = memo[i + 1][j];
      } else {
        memo[i][j] = std::max(memo[i + 1][j], memo[i + 1][j - w[i]] + v[i]);
      }
    }
  }

  return memo[0][weight];
}

void pattern1() {
  int n = 4;

  int w[] = {2, 1, 3, 2};
  int v[] = {3, 2, 4, 2};

  int W = 5;

  clock_t start = clock();
  printf("%d\n", solve1(n, w, v, 0, W));
  clock_t end = clock();     // 終了時間
  cout << "duration = " << (double)(end - start) / CLOCKS_PER_SEC << "sec.\n";

  // メモ化テーブル
  start = clock();
  int memo[5][100];
  memset(memo, -1, sizeof(memo));
  printf("%d\n", solve2(n, w, v, 0, W, memo));
  end = clock();     // 終了時間
  cout << "duration = " << (double)(end - start) / CLOCKS_PER_SEC << "sec.\n";

  // 漸化式を解決
  memset(memo, 0, sizeof(memo));
  printf("%d\n", solve3(n, w, v, W, memo));
}

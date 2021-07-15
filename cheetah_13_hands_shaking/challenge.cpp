#include <string>
#include <iostream>

using namespace std;

/**
 * 丸いテーブル
 * n人
 * 他の誰かと必ず1人握手
 * 握手は互いに腕が交差しない
 * 組み合わせを返す
 * カタランの数
 */
using ll = long long;

ll solve(int n) {

  ll *dp = new ll[n / 2 + 1];
  dp[0] = 1;

  for (int i = 1; i <= n / 2; i++) {
    for (int j = 0; j < i; j++) {
      dp[i] += dp[j] * dp[i - j - 1];
    }
  }

  return dp[n / 2];
}

int main() {
  int a = solve(2);
  cout << a << endl; // 1
  cout << solve(4) << endl; // 2
  cout << solve(8) << endl; // 14

  return 0;
}
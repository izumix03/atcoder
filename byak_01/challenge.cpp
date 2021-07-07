#include <algorithm>
#include <vector>
#include <ctime>
#include <iostream>

using namespace std;
int memo[100][100];

/**
 * 部分和問題
 * N個の正の整数a0,a1,...,aN－1と正の整数Wが与えられます．
 * a0,a1,...,aN－1の中から何個かの整数を選んで総和をWとすることができるかどうかを判定してください．
 * たとえばN＝5,W＝10,a＝{1,2,4,5,11}の場合には，a0＋a2＋a3＝1＋4＋5＝10ですから“Yes”となります
 * @return
 */
bool dfs(const vector<int> &a, int index, int sum, int w) {
  if (a.size() == index) return sum == w;

  // ここに イコール 含むとアウト
  if (sum > w) return false;
  if (sum == w) return true;

  return dfs(a, index + 1, sum, w) || dfs(a, index + 1, sum + a.at(index), w);
}

// 動的計画法
int dynamic(const vector<int> &a, int index, int sum, int w) {
  if (a.size() == index) return sum == w;

  if (memo[index][sum] != -1) {
    return memo[index][sum];
  }

  if (sum > w) return memo[index][sum] = 0;
  if (sum == w) return 1;

  return memo[index][sum] = max(dynamic(a, index + 1, sum + a.at(index), w),
                                dynamic(a, index + 1, sum, w));
}

void solve(const vector<int> &a, int w) {
  clock_t start = clock();
  printf("%s\n", dfs(a, 0, 0, w) ? "Yes" : "No");
  clock_t end = clock();     // 終了時間
  cout << "duration = " << (double) (end - start) / CLOCKS_PER_SEC << "sec.\n";

  start = clock();
  memset(memo, -1, sizeof(memo));
  printf("%s\n", dynamic(a, 0, 0, w) == 1 ? "Yes" : "No");
  end = clock();     // 終了時間
  cout << "duration = " << (double) (end - start) / CLOCKS_PER_SEC << "sec.\n";
}

int main() {
  solve({1, 2, 4, 5, 11}, 10);
  solve({1, 5, 8, 11}, 10);
  return 0;
}

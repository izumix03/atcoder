#include <string>
#include <iostream>
#include <vector>

using namespace std;

// 動的計画法
// どの住人も隣人を嫌ってる = 隣人が寄付したら自分は寄付しません。
// 最後の要素は最初の要素と隣合わせです。
// int donations[] + {0,1,2,3,4} // example
//   2 <= donations.size() <= 40
//   1 <= 寄付額 <= 1000
// 最も多くなる寄付額はいくら？


int solve(vector<int> donations, int i, int sum, bool used) {
  if (i >= donations.size()) {
    return sum;
  }
  int maxSum = solve(donations, i + 1, sum, used);

  if (i + 1 < donations.size() || (i + 1 >= donations.size() && !used)) {
    if (i == 0) {
      maxSum = max(maxSum, solve(donations, i + 2, sum + donations[i], true));
    } else {
      maxSum = max(maxSum, solve(donations, i + 2, sum + donations[i], used));
    }
  }
  return maxSum;
}

int answer(vector<int> donations) {
  int i;
  int ans = 0;

  int N = int(donations.size());
  int *dp = new int[N];

  // 0を使う場合
  for (i = 0; i < N - 1; i++) {
    dp[i] = donations[i];
    if (i > 0) dp[i] = max(dp[i], dp[i - 1]);
    if (i > 1) dp[i] = max(dp[i], dp[i - 2] + donations[i]);
    ans = max(ans, dp[i]);
  }

  // 1を使う場合
  for (i = 0; i < N - 1; i++) {
    dp[i] = donations[i+1];
    if (i > 0) dp[i] = max(dp[i], dp[i - 1]);
    if (i > 1) dp[i] = max(dp[i], dp[i - 2] + donations[i+1]);
    ans = max(ans, dp[i]);
  }
  return ans;
}

int main() {
  vector<int> donations1 = {10, 3, 2, 5, 7, 8};
  cout << solve(donations1, 0, 0, false) << endl; // 19
  cout << answer(donations1) << endl; // 19

  vector<int> donations2 = {11, 15};
  cout << solve(donations2, 0, 0, false) << endl; // 15
  cout << answer(donations2) << endl; // 15

  vector<int> donations3 = {7, 7, 7, 7, 7, 7, 7};
  cout << solve(donations3, 0, 0, false) << endl; // 21
  cout << answer(donations3) << endl; // 21

  vector<int> donations4 = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
  cout << solve(donations4, 0, 0, false) << endl; // 16
  cout << answer(donations4) << endl; // 16

  vector<int> donations5 = {94, 40, 49, 65, 21, 21, 106, 80, 92, 81, 679, 4, 61,
                            6, 237, 12, 72, 74, 29, 95, 265, 35, 47, 1, 61, 397,
                            52, 72, 37, 51, 1, 81, 45, 435, 7, 36, 57, 86, 81, 72};
  cout << solve(donations5, 0, 0, false) << endl; // 2926
  cout << answer(donations5) << endl; // 2926

  return 0;
}
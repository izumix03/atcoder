#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

/**
 * 入力リストから1つの数字を選び、値を1増加させえ、リスト全ての積が最大になるようにする
 * int numbers[]
 *
 * @return 得られる積の最大値
 */

ll solve(vector<int> numbers) {
  // FIXME: ソートの方が良かった
  int m = *min_element(numbers.begin(), numbers.end());
  bool replaced = false;
  ll result = 1;

  for (const int& n: numbers) {
    if (n == m && !replaced) {
      result *= n + 1;
      replaced = true;
      continue;
    }
    result *= n;
  }

  return result;
}


int main() {
  cout << solve({1, 2, 3}) << endl; // 12
  cout << solve({1, 3, 2, 1, 1, 3}) << endl; // 36
  cout << solve({1000, 999, 998, 997, 996, 995}) << endl; // 986074810223904000
  cout << solve({1, 1, 1, 1}) << endl; // 2
}
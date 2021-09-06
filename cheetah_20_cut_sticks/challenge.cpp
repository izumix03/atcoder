
#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/**
 * ☆ジョンは棒を持っている
 * int sticks[] = 1本の棒の長さ
 * C 回切断することが可能
 * 切断すると、任意の正数の長さの2本になる
 * ※切断した棒をさらに切断することも可能
 *
 * 切断した後、長さ順にソートし、 K 番目の棒を選択
 * 最大の長さはいくつになるでしょうか？
 *
 * 最低 K 本まで切断しないといけません。
 */

vector<double> result = {};

void dfs(int c, int k) {
  if (c == 0) {
    return;
  }

  if (result.size() >= k && result[k-1] < result[0] / 2) {
    double r = result[0] / 2;
    result.erase(result.begin());
    result.push_back(r);
    result.push_back(r);
    sort(result.begin(), result.end(), greater<>());
    dfs(c - 1, k);
  } else if (result.size() >= k) {
    return;
  } else {
    double r = result[result.size() - 1] / 2;
    result.pop_back();
    result.push_back(r);
    result.push_back(r);
    sort(result.begin(), result.end(), greater<>());
    dfs(c - 1, k);
  }
}

//double solve(const vector<int>& sticks, int c, int k) {
//  result = {};
//  for (double s : sticks) {
//    result.push_back(s);
//  }
//  sort(result.begin(), result.end(), greater<>());
//
//  dfs(c, k);
//  return result[k-1];
//}
//


double solve(const vector<int>& sticks, int c, int k) {
  double low = 0;
  double high = 1e9;

  int i, j;
  for (i = 0; i < 100; i++) {
    long long count = 0;
    double mid = (low + high) / 2; // 真ん中の値

    long long cut = 0;
    for (j = 0; j < sticks.size(); j++) {
      int next = (sticks[j] / mid); // 本数
      cut += max(0, (next -1)); // cut 回数
      count += next;
    }
    count -= max(0, int(cut - c));
    if (count >= k) low = mid;
    else high = mid;
  }
  return low;
}

int main() {
  // A, B, K
  cout<< solve({5, 8}, 1, 1) << endl; // 8.0
  cout << "answer, 8.0" << endl;

  cout << solve({5, 8}, 1, 2) << endl; // 5.0
  cout << "answer, 5.0" << endl;
  cout << solve({5, 8}, 1, 3) << endl; // 4.0
  cout << "answer, 4.0" << endl;
  cout << solve({1000000000, 1000000000, 1}, 2, 5) << endl; // 1
  cout << "answer, 1.0" << endl;
  cout << solve({76, 594, 17, 6984, 26, 57, 9, 876, 5816, 73, 969, 527, 49}, 789, 459) << endl; // 34.92
  cout << "answer, 34.92" << endl;

  return 0;
}
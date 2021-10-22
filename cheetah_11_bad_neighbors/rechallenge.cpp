#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// 動的計画法
// 最も多くなる寄付額はいくら？
// int donations[] + {0,1,2,3,4} // example
//   2 <= donations.size() <= 40
//   1 <= 寄付額 <= 1000
//
// どの住人も隣人を嫌ってる = 隣人が寄付したら自分は寄付しません。
// 最後の要素は最初の要素と隣合わせです。

int saiki(vector<int> donations, int index, int sum) {
  if (index > donations.size() - 1) {
    return sum;
  }
  sum += donations[index];
  return max(saiki(donations, index + 2, sum),
             saiki(donations, index + 3, sum));
}

int solve(const vector<int>& donations) {
  return max(saiki(donations, 0, 0), saiki(donations, 1, 0));
}

int main() {
  cout << solve({10, 3, 2, 5, 7, 8}) << endl; // 19
  cout << solve({1, 10, 3, 2, 10, 7, 8}) << endl; // 28
  cout << solve({11, 15}) << endl; // 15
  cout << solve({7, 7, 7, 7, 7, 7, 7}) << endl; // 21
  cout << solve({1, 2, 3, 4, 5, 1, 2, 3, 4, 5}) << endl; // 16
  cout << solve({94, 40, 49, 65, 21, 21, 106, 80, 92, 81, 679, 4, 61,
                 6, 237, 12, 72, 74, 29, 95, 265, 35, 47, 1, 61, 397,
                 52, 72, 37, 51, 1, 81, 45, 435, 7, 36, 57, 86, 81, 72}) << endl; // 2926
  return 0;
}
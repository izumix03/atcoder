//
// Created by mix on 2021/09/07.
//
#include <vector>
#include <iostream>

using namespace std;

/**
 * ボトル: N本
 * 容量: capacities[i]
 * 注いだ量: bottles[i]
 *
 * 再分配したい
 * M回の操作を行う
 *
 * from[i] -> to[i]
 *  ・空になる or 満杯になる = stop
 *
 * @return 移し替え済みの結果
 */

void solve(vector<int> capacities,
           vector<int> bottles,
           vector<int> fromId,
           vector<int> toId) {
  for (int i = 0; i < fromId.size(); i++) {
    int from = fromId[i];
    int to = toId[i];
    int quantity = min((capacities[to] - bottles[to]), bottles[from]);
    bottles[from] -= quantity;
    bottles[to] += quantity;
  }

  for (int b: bottles) {
    cout << b  << ',';
  }
  cout << endl;
}

void main() {
  solve({20, 20}, {5, 8}, {0}, {1}); // 0, 13
  solve({10, 10}, {5, 8}, {0}, {1}); // 3, 10
  solve({30, 20, 10}, {10, 5, 5}, {0, 1, 2}, {1, 2, 0}); // 10, 10, 0
  solve({14, 35, 86, 58, 25, 62},
        {6, 34, 27, 38, 9, 60},
        {1, 2, 4, 5, 3, 3, 1, 0},
        {0, 1, 2, 4, 2, 5, 3, 1}); // 0, 14, 65, 35, 25, 35
  solve({700000, 800000, 900000, 1000000},
        {478478, 478478, 478478, 478478},
        {2, 3, 2, 0, 1},
        {0, 1, 1, 3, 2}); // 0, 156956, 900000, 856956
}
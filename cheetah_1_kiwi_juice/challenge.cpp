#include <cstdio>
#include <vector>

using namespace std;

// ■ simulation
// 0 ~ n-1
// capacities[i] 許容範囲
// bottles[i] 注いだ
// fromId[i] -> toId[i]
//   fromId[i] empty || toId[i] full
//     -> stop!!
void solve1() {
  vector<int> capacities = {700000, 800000, 900000, 1000000};
  vector<int> bottles = {478478, 478478, 478478, 478478};
  vector<int> fromId = {2, 3, 2, 0, 1};
  vector<int> toId = {0, 1, 1, 3, 2};
  // {0, 156956, 90000, 856956}

  for (int i = 0; i < fromId.size(); i++) {
    int flow = std::min(bottles[fromId[i]], capacities[toId[i]] - bottles[toId[i]]);
    bottles[fromId[i]] -= flow;
    bottles[toId[i]] += flow;
  }

  for (int bottle : bottles) {
    printf("%d\n", bottle);
  }
}

void main() {
  solve1();
  return 0;
}

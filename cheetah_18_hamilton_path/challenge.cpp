#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * N 個の都市がある
 * 各都市同士は双方向の道路で繋がれている
 *
 * 次のルールを満たす移動の数を、1,000,000,007 で割り、余りを返して下さい
 *
 * - 1つの都市から始めて、N-1個の道路を通って別の都市で移動を終える
 * - 各都市を1回だけ訪れる
 * - string roads[] で i番目のの要素の j番目が 'Y' なら i -> j(or j -> i) の道路を通る
 *
 * string roads[] : 2 <= length <= 50
 * roads[i]: 2 <= length <= 50
 * roads[i][j]: 'Y' or 'N'
 * roads[i][i]: 'N'
 * roads[i][j]: roads[j][i]
 *
 * 注意: roads が示すのは「通ることが必須かどうか」、全部の街には通路がある
 */

bool visited[50] = {false};

void dfs(int city, vector<string> roads) {
  visited[city] = true;
  for (int i = 0; i < roads[city].size(); i++) {
    if (roads[city].substr(i, 1) == "Y" && !visited[i]) dfs(i, roads);
  }
}

int solve(vector<string> roads) {
  // Y が 3つ以上あれば 0

  int group = 0, free = 0;
  int connect[50] = {0};
  for (auto &v : visited) {
    v = false;
  }


  long long sum = 1;

  // Y が 3つ以上あれば 0
  for (int i = 0; i < roads.size(); i++) {
    int y = 0;
    for (int j = 0; j < roads[i].size(); j++) {
      if (roads[i].substr(j, 1) == "Y") {
        if (2 < ++y) return 0;
      }
    }
    // 固定数を加算
    connect[i] = y;
  }

  for (int i = 0; i < roads.size(); i++) {
    if (connect[i] == 0) {
      // 全部自由
      visited[i] = true;
      free++;
    } else if (connect[i] == 1 && !visited[i]) {
      // 1つ自由から始める
      group++;
      // visited をたどりながら更新(2この場合も必ずとおる)
      dfs(i, roads);
    }
  }

  // 全部通っていない場合は 0
  for (int i = 0; i < roads.size(); i++) {
    if (!visited[i]) return 0;
  }

  // (group + free)!
  // なぜ成り立つかわからないかも
  for (int i = 0; i < group + free; i++) {
    sum = sum * (i + 1) % 1000000007;
  }

  // 両端を入れ替え可能なので、 (group + free)! * (2 * group)
  // ちょっとわからない。。
  for (int i = 0; i < group; i++) {
    sum = sum * 2 % 1000000007;
  }

  return int(sum);
}

void main() {
  cout << solve({"NYN", "YNN", "NNN"}) << endl; // 4
  cout << solve({"NYYY", "YNNN", "YNNN", "YNNN"}) << endl; // 0
  cout << solve({"NYY", "YNY", "YYN"}) << endl; // 0
  cout << solve({"NNNNNY",
                 "NNNNYN",
                 "NNNNYN",
                 "NNNNNN",
                 "NYYNNN",
                 "YNNNNN"}) << endl; // 24

  return 0;
}
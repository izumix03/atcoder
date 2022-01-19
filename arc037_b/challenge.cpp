#include <iostream>
#include <vector>

using namespace std;


// https://atcoder.jp/contests/arc037/tasks/arc037_b

// 頂点 N
// 辺 M
int N = 0, M = 0;
vector<int> used;

bool dfs(vector<vector<int>> input, vector<bool> &seen, int root) {
  for (int i = 0; i < input.size(); i++) {
    bool skip = false;
    for (int j : used) {
      if (j == i) skip = true;
    }
    if (skip) continue;
    int target;
    if (input[i][0] == root) {
      target = input[i][1];
    } else if (input[i][1] == root) {
      target = input[i][0];
    } else {
      continue;
    }
    used.push_back(i);
    if (seen[target]) {
      // 閉路
      return false;
    }
    seen[target] = true;
    if (!dfs(input, seen, target)) {
      return false;
    }
  }
  // 閉路判定が一度もなく回れたので true
  return true;
}

int main() {
  cin >> N;
  cin >> M;

  vector<vector<int>> input(M, vector<int>(2));

  for (int i = 0; i < M; i++) {
    cin >> input[i][0];
    cin >> input[i][1];
  }

  vector<bool> seen(N + 1, false);

  int cnt = 0;
  // 木の数
  for (int i = 1; i <= N; i++) {
    if (seen[i]) continue;
    seen[i] = true;
    if (dfs(input, seen, i)) cnt++;
  }

  cout << cnt << endl;

  return 0;
}

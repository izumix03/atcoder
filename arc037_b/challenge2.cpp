#include <iostream>
#include <vector>

using namespace std;


// https://atcoder.jp/contests/arc037/tasks/arc037_b

// 頂点 N
// 辺 M

#define MAX_N 100
int N, M;
vector<int> condition[MAX_N];
vector<bool> done(MAX_N, false);

void input() {
  int u, v;
  cin >> N >> M;

  while (cin >> u >> v) {
    u--, v--;
    condition[u].push_back(v);
    condition[v].push_back(u);
  }
  done.resize(N);
}

bool dfs_isTree(int node, int parent) {
  done[node] = true;
  if (condition[node].empty()) return true;

  for (auto target: condition[node]) {
    if (target == parent) continue;
    if (done[target]) return false;
    if (!dfs_isTree(target, node)) {
      return false;
    }
  }

  return true;
}

void solve() {
  int counter = 0;
  for (int node = 0; node < N; node++) {
    if (done[node]) continue;
    counter += dfs_isTree(node, 0);
  }
  cout << counter << endl;
}

int main() {
  input();
  solve();
  return 0;
}

#include <cstdio>
#include <vector>

using namespace std;
//using ll = long long;

class UnionFind {
public:
  vector<int> parents;
  vector<int> ranks;

  explicit UnionFind(int N) {
    parents = vector<int>(N);
    for (int i = 0; i < N; i++) {
      parents[i] = i;
    }
    ranks = vector<int>(N, 0);
  }

  int root(int x) {
    if (parents.at(x) == x) return x;
    return parents.at(x) = root(parents.at(x));
  }

  void unite(int x, int y) {
    x = root(x);
    y = root(y);

    if (x == y) return;

    if (ranks.at(x) < ranks.at(y)) {
      parents.at(x) = y;
    } else {
      parents.at(y) = x;
      // 同じ高さなら、親に+1
      if (ranks.at(x) == ranks.at(y)) ranks.at(x)++;
    }
  }

  bool same(int x, int y) {
    return root(x) == root(y);
  }
};

// ■union-tree
// 動物の数: N
// 種類: A, B, C
// 関係
//   A eats B
//   B eats C
//   C eats A
// 情報: K個
//   x = y
//   x eats y
// 正しくない情報の数を数えよう
// 1 <= N <= 50000
// 0 <= K <= 100000
void solve1() {
  int N = 100;
  int condition_count = 7;

  int T[] = {1, 2, 2, 2, 1, 2, 1};
  int X[] = {101, 1, 2, 3, 1, 3, 5};
  int Y[] = {1, 2, 3, 3, 3, 1, 5};

  // 初期化
  UnionFind uf = UnionFind(N * 3);

  int ans = 0;

  for (int i = condition_count-1; i >= 0; i--) {
    int t = T[i];
    int x = X[i] - 1; // index にするため
    int y = Y[i] - 1; // index にするため

    // 明らかに正しくない場合
    if (x < 0 || N <= x || y < 0 || N <= y) {
      ans++;
      continue;
    }

    if (t == 1) {
      // 同じ種類
      if (uf.same(x, y + N) || uf.same(x, y + 2 * N)) {
        // 矛盾する？良くわからない。。
        ans++;
      } else {
        // 矛盾しないなら統合
        uf.unite(x, y);
        uf.unite(x + N, y + N);
        uf.unite(x + N * 2, y + N * 2);
      }
    }

    if (t == 2) {
      if (uf.same(x, y) || uf.same(x, y + 2 * N)) {
        ans++;
      } else {
        uf.unite(x, y + N);
        uf.unite(x + N, y + 2 * N);
        uf.unite(x + 2 * N, y);
      }
    }
  }

  printf("%d\n", ans);
}

int main() {
  solve1();
  return 0;
}

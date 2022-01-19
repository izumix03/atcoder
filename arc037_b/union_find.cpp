#include <iostream>
#include <vector>

using namespace std;


// https://atcoder.jp/contests/arc037/tasks/arc037_b

// 頂点 N
// 辺 M

class UnionFind {
public:
  // 親の番号を格納する。親だった場合は-(その集合のサイズ)
  vector<int> Parent;

  UnionFind(int N) {
    Parent = vector<int>(N, -1);
  }

  // Aがどのグループに属しているか調べる
  int root(int A) {
    if (Parent[A] < 0) return A;
    return Parent[A] = root(Parent[A]);
  }

  // 自分のいるグループの頂点数を調べる
  int size(int A) {
    return -Parent[root(A)];//親をとってきたい]
  }

  // AとBをくっ付ける
  bool connect(int A, int B) {
    // AとBを直接つなぐのではなく、root(A)にroot(B)をくっつける
    A = root(A);
    B = root(B);
    if (A == B) {
      //すでにくっついてるからくっ付けない
      return false;
    }

    // 大きい方(A)に小さいほう(B)をくっ付ける
    // 大小が逆だったらひっくり返す
    if (size(A) < size(B)) {
      swap(A, B);
    }

    // Aのサイズを更新する
    Parent[A] += Parent[B];
    // Bの親をAに変更する
    Parent[B] = A;

    return true;
  }
};

#define MAX_N 100
int N, M;
vector<int> g1, g2;
vector<bool> done(MAX_N, false);

void input() {
  int u, v;
  cin >> N >> M;

  for(int i = 0; i < M; i++) {
    cin >> u >> v;
    g1.push_back(u);
    g2.push_back(v);
  }
  done.resize(N);
}
#include <set>

void solve() {
  UnionFind uni(MAX_N);

  set<int> looped;
  for (int i = 0; i < M; i++) {
    if (uni.root(g1[i]) == uni.root(g2[i])) {
      looped.insert(uni.root(g1[i]));
    }
    uni.connect(g1[i], g2[i]);
  }

  set<int> tree;
  for (int i = 1; i <= N; i++) {
    if (looped.find(uni.root(i)) != looped.end()) {
      continue;
    }
    tree.insert(uni.root(i));
  }

  cout << tree.size() << endl;
}

int main() {
  input();
  solve();
  return 0;
}

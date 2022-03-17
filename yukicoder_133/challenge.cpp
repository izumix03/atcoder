#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * https://yukicoder.me/problems/no/133
 * AとBはカードゲームが好き
 * 数は 1以上 2^N未満
 * N枚ずつ配られる
 * 数字が大きい方が勝ち、二度と使えない、勝数が同じなら引き分け
 * Aが勝つ確率を返せ
 * 1 <= N <= 4
 */

int N;
vector<int> a;
vector<int> b;

void input() {
  cin >> N;

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < N; j++) {
      int x;
      cin >> x;
      if (i == 0) {
        a.push_back(x);
      } else {
        b.push_back(x);
      }
    }
  }
}

void solve() {
  sort(a.begin(), a.end());
  int total = 0, a_win = 0;
  do {
    int a_up = 0;
    for (int i = 0; i < N; i++) {
      if (a.at(i) > b.at(i)) {
        a_up++;
      }
      if (a.at(i) < b.at(i)) {
        a_up--;
      }
    }
    if (a_up > 0) {
      a_win++;
    }
    total++;
  } while(next_permutation(a.begin(), a.end()));
  cout << a_win * 1.0 / total  * 1.0<< endl;
}

int main() {
  input();
  solve();
  return 0;
}

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n, k;
vector<string> cards;

// /* next combination */
// int next_combination(int sub) {
//     int x = sub & -sub, y = sub + x;
//     // cout << "sub: " << bitset<5>(sub) << endl;
//     // cout << "-sub: " << bitset<5>(-sub) << endl;
//     // cout << "x: " << bitset<5>(x) << endl;
//     // cout << "y: " << bitset<5>(y) << endl;
//     // cout << "sub & ~y: " << bitset<5>(sub & ~y) << endl;
//     // cout << "(sub & ~y) / x: " << bitset<5>((sub & ~y) / x) << endl;
//     // cout << "((sub & ~y) / x) >> 1: " << bitset<5

void input() {
  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    string x;
    cin >> x;
    cards.push_back(x);
  }
}
set<string> answers;

void dfs(vector<int> indexes) {
  // 全部揃ったら追加
  if (indexes.size() == k) {
    string val;
    for (int ind: indexes) {
      val += cards[ind];
    }
    answers.insert(val);
    indexes.pop_back();
    return;
  }

  for (int i = 0; i < n; i++) {
    bool ok = true;
    for (int index : indexes) {
      if (i == index) {
        ok = false;
        break;
      }
    }
    if (!ok) continue;

    indexes.push_back(i);
    dfs(indexes);
    indexes.pop_back();
  }
  indexes.pop_back();
}

void solve() {
  for (int i = 0; i < n ; i++) {
    // 1つ目を選ぶ
    dfs(vector<int>{i});
  }
}

int main() {
  input();
  solve();
  cout << answers.size() << endl;
  return 0;
}

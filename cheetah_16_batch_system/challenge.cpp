#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct PersonJob {
  int total{};
  vector<int> indexes;
};

/**
 * 貪欲法
 *
 * int duration[], 1 <= size <= 50, 1 <= value <= 1000000000
 * string user[], 1 <= size <= 50,  1 <= value.length <= 50
 * n個の保留ジョブ
 *  ・1つのジョブは上記2つの配列
 *
 * i番目: duration[i] 必要な時間, user[i] が依頼した人
 *
 * ・1人のユーザーは複数のジョブを依頼できる
 * ・ユーザーは依頼したすべてのジョブが終わるまで待たないといけない
 *
 * ★すべてのユーザーの平均待ち時間が最小化するようにスケジューリングしよう
 * ★ジョブ番号をint配列で返す
 * ※もし複数ある場合、辞書順で先頭にくる結果のみを返す
 */

void solve(vector<int> duration, vector<string> user) {
  // 人: 人とトータルと index リストのMAP 作る
  map<string, PersonJob> m;

  for (int i = 0; i < duration.size(); i++) {
    string name = user.at(i);
    if (m.find(name) == m.end()) {
      m[name] = PersonJob{
          duration.at(i),
          {i}
      };
      continue;
    }
    m.at(name).total += duration.at(i);
    m.at(name).indexes.push_back(i);
  }

  // トータル+人で並べ替え
  typedef pair<string, PersonJob> PAIR;
  struct cmp {
    bool operator()(const PAIR &a, const PAIR &b) {
      if (a.second.total == b.second.total) {
        return a.first > b.first;
      }
      return a.second.total > b.second.total;
    };
  };

  priority_queue<PAIR, vector<PAIR>, cmp> pq(m.begin(), m.end());
  while (!pq.empty()) {
    PAIR top = pq.top();
    pq.pop();
    for (int i: top.second.indexes) {
      cout << i << ",";
    }
  }
  cout << endl;
}

void answer(vector<int> duration, vector<string> user) {
  int N = int(duration.size());

  map<string, int> jobTime;
  for (int n = 0; n < N; n++) jobTime[user[n]] += duration[n];

  vector<bool> done(N);
  vector<int> ans;

  while (ans.size() < N) {
    string next;
    for (int n = 0; n < N; n++) {
      if (!done[n] && (next.empty() || jobTime[user[n]] < jobTime[next])) {
        // 残っている中で一番少ない時間の人
        next = user[n];
      }
    }
    for (int n = 0; n < N; n++) {
      if (user[n] == next) {
        done[n] = true;
        ans.push_back(n);
      }
    }
  }

  for (int i: ans) {
    cout << i << ",";
  }
  cout << endl;
}


int main() {
  solve({400, 100, 100, 100}, {"Danny Messer", "Stella Bonasera", "Stella Bonasera", "Mac Taylor"}); // {3, 1, 2 , 0}
  solve({200, 200, 200}, {"Gil", "Sarah", "Warrick"}); // {0, 1, 2}
  solve({100, 200, 50}, {"Horatio Caine", "horatio caine", "YEAAAAAAH"}); // {2, 0, 1}
  answer({400, 100, 100, 100}, {"Danny Messer", "Stella Bonasera", "Stella Bonasera", "Mac Taylor"}); // {3, 1, 2 , 0}
  answer({200, 200, 200}, {"Gil", "Sarah", "Warrick"}); // {0, 1, 2}
  answer({100, 200, 50}, {"Horatio Caine", "horatio caine", "YEAAAAAAH"}); // {2, 0, 1}

  return 0;
}
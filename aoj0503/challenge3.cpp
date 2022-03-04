#include <iostream>
#include <map>
#include <queue>

using namespace std;

#define MAX_N 15000000

/**
 * 10 の 8乗までいける
 *
 * https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0503
 * 大きさが違う n 個のコップ
 * 3つのトレイ A,B,C
 *  ・1トレイ複数コップ可能
 *  ・小さいのが下になる
 * M回でいける？
 *
 * AかCにまとめるまでに何回必要？
 *
 * ・1回1カップ、一番上のみ
 * ・1つしか横にずらせない
 *
 * 1 <= n <= 15
 * 1 <= m <= 15000000
 *
 * 3 通り ✕ 最大 15個
 */


// typedef long long ll;
typedef int64_t ll;

// #define dump(x) cout << #x << " = " << (x) << endl;
#define dump(x) ;

template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

vector<int> split(string str, char separator) {
  vector<int> result;
  // 古いコンパイラでは通らない
  // std::stringstream ss{str};
  std::stringstream ss;
  ss << str;
  std::string buf;
  while (std::getline(ss, buf, separator)) {
    // if (buf == "\n") {
    //     break;
    // }
    result.push_back(stoi(buf));
  }
  return result;
}

struct dataset {
  ll n;
  ll m;
  vector<int> a;
  vector<int> b;
  vector<int> c;
};

struct state {
  ll a;
  ll b;
  ll c;
  ll cnt;
};

ll flip(ll n, int index) { return bitset<15>(n).flip(index).to_ulong(); }

map<ll, ll> bit_width_map;

// 0 index で返す
int bit_width(ll n) {
  auto h = bit_width_map.find(n);
  if (h != bit_width_map.end()) {
    return h->second;
  }
  for (int i = 14; i >= 0; i--) {
    if (bitset<15>(n).test(i)) {
      bit_width_map.insert(make_pair(n, i));
      return i;
    }
  }
  return 0;
}

ll pattern_num(state st, int len) {
  ll val = 0;
  ll pow3 = 1;
  for (int i = 0; i < len; i++) {
    if (bitset<15>(st.a).test(i)) {
      val += pow3 * 0;
    }
    if (bitset<15>(st.b).test(i)) {
      val += pow3 * 1;
    }
    if (bitset<15>(st.c).test(i)) {
      val += pow3 * 2;
    }
    pow3 *= 3;
  };
  return val;
}

ll all_c_pattern_num() {
  bitset<15> bs("111111111111111");
  state mock_st = {0, 0, (ll)bs.to_ulong(), 0};
  return pattern_num(mock_st, 15);
}

// BFS
// function 幅優先探索(v)
//     Q ← 空のキュー
//     v に訪問済みの印を付ける
//     v を Q に追加
//     while Q が空ではない do
//         v ← Q から取り出す
//         v を処理する
//         for each v に接続している頂点 i do
//             if i が未訪問 then
//                 i に訪問済みの印を付ける
//                 i を Q に追加
vector<int> solve(vector<dataset> data) {
  for (auto d : data) {
    for (auto a_ : d.a) {
      dump(a_);
    }
    for (auto b_ : d.b) {
      dump(b_);
    }
    for (auto c_ : d.c) {
      dump(c_);
    }
    dump(d.m);
    dump(d.n);
  }
  vector<int> result;
  for (auto d : data) {
    ll a = 0, b = 0, c = 0;
    for (auto i : d.a) {
      a += 1 << (i - 1);
    }
    for (auto i : d.b) {
      b += 1 << (i - 1);
    }
    for (auto i : d.c) {
      c += 1 << (i - 1);
    }
    state st = {a, b, c, 0};
    queue<state> q;
    q.push(st);
    ll min_val = d.m + 1;
    ll loop_cnt = 0;
    // ll pattern = 1 << d.n;
    // BFS なので、最初に訪れたものが最短なので、cnt
    // を保持する必要はない ※
    // 2回だけ壁を壊せる迷路とかの場合は、壊せる壁の数とかは状態に必要
    // vector<vector<vector<bool>>> visited(
    //     pattern, vector<vector<bool>>(pattern,
    //     vector<bool>(pattern)));
    // → この配列は大きすぎて初期化が (3^15)^3 のサイズになり Timeout
    // してしまうので以下の形を利用する
    vector<bool> visited(all_c_pattern_num());
    while (!q.empty()) {
      loop_cnt++;
      auto s = q.front();
      q.pop();

      if (s.b == 0 && (s.a == 0 || s.c == 0)) {
        //成功
        chmin(min_val, s.cnt);
        // これ以上やってもこれより良いスコアは出ないので打ち切り
        // ただ、他のケースもあるので break はダメ
        continue;
      }
      if (s.cnt >= min_val) {
        // これ以上やってもこれより良いスコアは出ないので打ち切り
        continue;
      }
      // if (visited.at(s.a).at(s.b).at(s.c)) {
      //     continue;
      // }
      // visited.at(s.a).at(s.b).at(s.c) = true;
      // 以下に書き換え
      ll pattern = pattern_num(s, d.n);
      if (visited.at(pattern)) {
        continue;
      }
      visited.at(pattern) = true;

      // MSB
      // 古いコンパイラ?ではこの関数がないらしい
      // auto msba = std::__bit_width(s.a);
      // auto msbb = std::__bit_width(s.b);
      // auto msbc = std::__bit_width(s.c);
      auto msba = bit_width(s.a);
      auto msbb = bit_width(s.b);
      auto msbc = bit_width(s.c);

      // if (msba > msbb) {
      //     q.push({flip(a, msba), flip(b, msba), c, s.cnt + 1});
      // } else {
      //     q.push({flip(a, msbb), flip(b, msbb), c, s.cnt + 1});
      // }
      // ↑ これを簡単化
      auto maxab = max(msba, msbb);
      q.push({flip(s.a, maxab), flip(s.b, maxab), s.c, s.cnt + 1});
      auto maxbc = max(msbb, msbc);
      q.push({s.a, flip(s.b, maxbc), flip(s.c, maxbc), s.cnt + 1});
    }
    dump(loop_cnt);
    result.push_back(min_val <= d.m ? min_val : -1);
  }
  return result;
}

vector<dataset> parse() {
  vector<dataset> result;
  while (true) {
    ll n, m;
    cin >> n >> m;
    if (n == 0 && m == 0) {
      break;
    }
    string _, as, bs, cs;
    // 最初の行も考慮する必要があるみたい。詳細不明
    getline(cin, _);
    getline(cin, as);
    getline(cin, bs);
    getline(cin, cs);
    auto a = split(as, ' ');
    auto b = split(bs, ' ');
    auto c = split(cs, ' ');
    a.erase(a.begin());
    b.erase(b.begin());
    c.erase(c.begin());
    result.push_back({n, m, a, b, c});
  }
  return result;
}

vector<dataset> insert() {
  // 10 10000
  // 4 1 4 5 9
  // 3 2 3 7
  // 3 6 8 10
  // 0 0

  vector<dataset> result;
  vector<int> a;
  a.push_back(1);
  a.push_back(4);
  a.push_back(5);
  a.push_back(9);
  vector<int> b;
  b.push_back(2);
  b.push_back(3);
  b.push_back(7);
  vector<int> c;
  c.push_back(3);
  c.push_back(6);
  c.push_back(8);
  c.push_back(10);
  result.push_back({10, 10000, a, b, c});
  return result;
}

// generated by oj-template v4.8.1
// (https://github.com/online-judge-tools/template-generator)
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  // 標準入力が取れない場合はこちらで代用
  // auto ans = solve(insert());
  auto ans = solve(parse());
  for (auto a : ans) {
    std::cout << a << '\n';
  }
  return 0;
}


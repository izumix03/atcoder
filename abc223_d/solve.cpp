#include <iostream>
#include <utility>
#include <vector>
#include <string>

using namespace std;
typedef pair<char, char> P;

vector<string> junretsu(string a) {
  // 組み合わせを作る
  if (a.size() == 1) {
    return {a};
  }
  vector<string> kouho;
  for (int i = 0; i < a.size(); i++) {
    string copyA = a;
    char tmp = copyA[i];
    // i を 消して
    string ss = copyA.erase(i, 1);
    vector<string> sub = junretsu(ss);
    for (const auto &s: sub) {
      kouho.push_back(tmp + s);
    }
  }
  return kouho;
}

string solve(string a, const vector<P> &p) {
  // 組み合わせを作る
  vector<string> kouho = junretsu(std::move(a));

  // 条件でフィルタリングする
  vector<string> filtered;
  for (const auto &k: kouho) {
    bool t = true;
    for (auto condition: p) {
      if (k.find(condition.first) > k.find(condition.second)) {
        t = false;
        break;
      }
    }
    if (t) filtered.push_back(k);
  }

  // ソートする
  sort(filtered.begin(), filtered.end());
  if (filtered.empty()) {
    return "-1";
  }
  return filtered[0];
}

int main() {
  string strN;
  cin >> strN;

//  int n = std::stoi(strN);

  string strM;
  cin >> strM;
  int m = stoi(strM);

  vector<char> a; // 使える数字

  for (int i = 0; i < m * 2; i++) {
    char tmp;
    cin >> tmp;

    a.push_back(tmp);
  }
  vector<P> p;
  for (int i = 0; i < a.size(); i += 2) {
    p.emplace_back(P(a[i], a[i + 1]));
  }

  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());

  string s(a.begin(), a.end());
  cout << solve(s, p) << endl;
  return 0;
}

/**
 * 1.2...N
 * 数列P
 * 辞書順で最小を返せ、なければ-1

 * 最大 N
 * 条件は M 個
 *
 * i = 1...Mで Pで AiはBiより先にくる
 */

/**
*
 string input;
  while( std::getline( std::cin, input ) )
  {
    std::cout << "getline:" << input << std::endl;
  }

  int input;
    while( std::cin >> input )
    {
        std::cout << "cin" << input << std::endl;
    }
*/
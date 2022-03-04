#include <iostream>
#include <utility>
#include <vector>
#include <string>

using namespace std;
typedef pair<char, char> P;

vector<string> junretsu(const string& a, const vector<P> &p) {
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
    vector<string> sub = junretsu(ss, p);
    for (const auto &s: sub) {
      string ttt = tmp + s;
      bool t = true;
      for (auto condition: p) {
        int f1 = ttt.find(condition.first);
        int f2 = ttt.find(condition.second);
        if (f1 >= 0 && f2 >= 0 && f1 > f2) {
          t = false;
          break;
        }
      }
      if (t) kouho.push_back(ttt);
    }
  }
  return kouho;
}

string solve(string a, const vector<P> &p) {
  // 組み合わせを作る
  vector<string> kouho = junretsu(std::move(a), p);

  // ソートする
  sort(kouho.begin(), kouho.end());
  if (kouho.empty()) {
    return "-1";
  }
  return kouho[0];
}

void main() {
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
  string result = solve(s, p);
  for (int i = 0; i < result.length(); i++) {
    cout << result[i];
    if (result != "-1" && result.length() != 0 && i != result.length()-1) {
      cout << " ";
    }
  }
  cout << endl;
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
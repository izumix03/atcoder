#include <iostream>
#include <vector>

using namespace std;

// 友達の数
// string friends[]: 'Y' or 'N'
// 友人の友人までは友人
// 回答と違うけどOK
int solve(vector<string> s) {
  int result = 0;

  for (int i = 0; i < s.size(); i++) {
    vector<bool> friends(s.size());

    for (int j = 0; j < s.size(); j++) {
      if (s[i][j] == 'Y') {
        friends[j] = true;
        for (int k = 0; k < s.size(); k++) {
          if (s[j][k] == 'Y') {
            friends[k] = true;
          }
        }
      }
    }

    int r = 0;
    for (auto f: friends) {
      if (f) r++;
    }
    result = max(result, r - 1);
  }
  return result;
}

int main() {
  cout << solve({"NNN", "NNN", "NNN"}) << endl; // 0
  cout << solve({"NYY", "YNY", "YYN"}) << endl; // 2
  cout << solve({"NYNNN", "YNYNN", "NYNYN", "NNYNY", "NNNYN"}) << endl; // 4
  cout << solve({
                    "NNNNYNNNNN",
                    "NNNNYNYYNN",
                    "NNNYYYNNNN",
                    "NNYNNNNNNN",
                    "YYYNNNNNNY",
                    "NNYNNNNNYN",
                    "NYNNNNNYNN",
                    "NYNNNNYNNN",
                    "NNNNNYNNNN",
                    "NNNNYNNNNN",
                }) << endl; // 8
  // もう一問は面倒でうつせない。。
}
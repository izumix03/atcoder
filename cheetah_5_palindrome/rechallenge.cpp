#include <iostream>
#include <string>

using namespace std;

// 回分かチェックする
// 違ったら 0 番目を末尾に入れてチェック
// 違ったら 1 番目を末尾に入れて index = 1 からチェック
// ...
void solve(string input, vector<int> vector) {
  int maxLen = input.length() * 2 - 1;

  // 文字増やす
  for (int i = 0; i < maxLen; i++) {
    // チェックする
    bool result = true;
    for (int j = 0; i + j < input.length() - 1 - j; j++) {
      if (input[j + i] != input[input.length() - 1 - j]) {
        result = false;
        break;
      }
    }
    if (result) return input.length() + i;
  }

  return maxLen;
}

// こういう解法もある模様。まあいいか
int answer(string s) {
  for (int i = int(s.size());; i++) {
    bool flag = true;
    for (int j = 0; j < s.size(); j++) {
      if ((i - j - 1) < s.size() && s[j] != s[i - j - 1]) {
        flag = false;
        break;
      }
    }
    if (flag) return i;
  }
}

// 回分を最短で作る
// string s: 1-50文字
void main() {
  cout << solve("abab", vector<int>()) << endl; // 5
  cout << solve("abacaba", vector<int>()) << endl; // 7
  cout << solve("qwerty", vector<int>()) << endl; // 11
  cout << solve("abdfhdyrbdbsdfghjkllkjhgfds", vector<int>()) << endl; // 27 -> 38
}
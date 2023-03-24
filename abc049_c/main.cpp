#include <iostream>
#include <string>
using namespace std;

/**
 * 英小文字 S が与えられる
 * T は最初空文字
 * Tの末尾に dream dreamer erase eraser のいずれかを追加する
 * 最終的に S=T となるか判定せよ
 * 1 <= |S| <= 10^5
 * @return
 */
int main() {
  string S;
  cin >> S;

  for (int i = S.size(); i > 0 ; i--) {
    if (i >= 5 && S.substr(i-5, 5) == "dream") {
      i -= 4;
    } else if (i >= 7 && S.substr(i-7, 7) == "dreamer") {
      i -= 6;
    } else if (i >= 5 && S.substr(i-5, 5) == "erase") {
      i -= 4;
    } else if (i >= 6 && S.substr(i-6, 6) == "eraser") {
      i -= 5;
    } else {
      cout << "NO" << endl;
      return 0;
    }
  }

  cout << "YES" << endl;
  return 0;
}


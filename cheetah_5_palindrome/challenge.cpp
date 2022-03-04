#include <cstdio>
#include <vector>

using namespace std;

// ■ 回文
// 文字列 s(1 < s < 50, 'a' ~ 'z')
// l >= 0 を追加して回文にする
// 最終的な文字列の長さが答え
void solve(char *s) {
  // 真ん中の初期値(i) = len(s) / 2(インデックス)
  // for i=len(s) / 2; i < len(s)
  //   true = true;
  //   for j(移動距離)=1;  i + j < (len(s) - 1)
  //     if s[i-j] != s[i+j] true = false && break
  //   if (true) printf i * 2 + 1
  // printf len(s) * 2 - 1
  int length = int(strlen(s));

  for (int i = length / 2; i < length; i++) {
    bool ok = true;
    bool ok2 = true;
    for (int j = 1; j < length - i; j++) {
      if (s[i - j] != s[i + j]) {
        ok = false;
        break;
      }
    }

    if (!ok) {
      for (int j = 1; j < length - i; j++) {
        if (s[i - j - 1] != s[i + j]) {
          ok2 = false;
        }
      }
    }
    if (ok) {
      printf("%d\n", 2 * i + 1);
      return;
    }
    if (ok2) {
      printf("%d\n", 2 * i);
      return;
    }
  }

  printf("%d\n", int(strlen(s)) * 2 - 1);
}

// 1文字ずつ増やして最初と最後を比較する
// 存在しない場合はOK、存在するけど一致しない場合はもう一文字増やす
void answer(char *s) {
  for (int i = strlen(s);; i++) {
    bool flag = true;

    for (int j = 0; j < strlen(s); j++) {
      // 反対の文字が存在し、違う文字なら 失敗
      if ((i - j - 1) < strlen(s)
          && s[j] != s[i - j - 1]
          ) {
        flag = false;
        break;
      }
    }
    if (flag) {
      printf("%d", i);
      return;
    }
  }
}


void main() {
//  solve("abab"); // 5: ababa
//  solve("abacaba"); // 7: abacaba
//  solve("qwerty"); // 11: qwertytrewq
//  solve("abdfhdyrbdbsdfghjkllkjhgfds "); // 38: abdfhdyrbdbsdfghjkllkjhgfdsbdbrydhfdba

  answer("abab"); // 5: ababa
//  answer("abacaba"); // 7: abacaba
//  answer("qwerty"); // 11: qwertytrewq
//  answer("abdfhdyrbdbsdfghjkllkjhgfds "); // 38: abdfhdyrbdbsdfghjkllkjhgfdsbdbrydhfdba
  return 0;
}


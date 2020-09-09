#include <string>
#include <iostream>
// http://judge.u-aizu.ac.jp/onlinejudge/finder.jsp?course=ITP1
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_8_C

using namespace std;

int main() {
  string s;
  int a[26] = {};
  char c;

  while (getline(cin, s)) {
    if (s.length() == 0) break;
    for (int i = 0; i < s.length(); i++) {
      c = tolower(s.c_str()[i]);
      if (c > 122) continue;
      a[c - 97] += 1;
    }
  }

  for (int i = 0; i < 26; i++) {
    printf("%c : %d\n", 97 + i, a[i]);
  }

  return 0;
}

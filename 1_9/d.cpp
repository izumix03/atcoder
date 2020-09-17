#include <string>
#include <iostream>
#include <algorithm>
// http://judge.u-aizu.ac.jp/onlinejudge/finder.jsp?course=ITP1
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_9_D

using namespace std;

int main() {
  string str, replace, cmd;
  int q, a, b;

  cin >> str;
  cin >> q;

  for (int i = 0; i < q; i++) {
    cin >> cmd >> a >> b;

    if (cmd == "replace") {
      cin >> replace;
      str.replace(a, b - a + 1, replace);
    } else if (cmd == "reverse") {
      replace = str.substr(a, b - a + 1);
      reverse(replace.begin(), replace.end());
      str.replace(a, b - a + 1, replace);
    } else {
      cout << str.substr(a, b - a + 1) << endl;
    }
  }

  return 0;
}

#include <string>
#include <iostream>
#include <algorithm>
// http://judge.u-aizu.ac.jp/onlinejudge/finder.jsp?course=ITP1
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_9_B

using namespace std;

int main() {
  string m;
  int count, h;
  cin >> m;

  while (m != "-") {
    cin >> count;

    for (int i = 0; i < count; i++) {
      cin >> h;
      m = m.substr(h) + m.substr(0, h);
    }
    cout << m << endl;

    cin >> m;
  }

  return 0;
}

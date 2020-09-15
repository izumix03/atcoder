#include <string>
#include <iostream>
#include <algorithm>
// http://judge.u-aizu.ac.jp/onlinejudge/finder.jsp?course=ITP1
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_9_A

using namespace std;

int main() {
  string W, T, TL;
  cin >> W;
  int count = 0;

  while (cin >> T) {
    if (T == "END_OF_TEXT") break;

    transform(T.begin(), T.end(), T.begin(), ::tolower);

    if (T == W)count++;
  }

  printf("%d\n", count);
  return 0;
}

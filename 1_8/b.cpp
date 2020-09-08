#include <string>
#include <iostream>
// http://judge.u-aizu.ac.jp/onlinejudge/finder.jsp?course=ITP1
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_8_B

using namespace std;

int main() {
  string s;
  int sum;

  while (getline(cin, s)) {
    sum = 0;
    if (s == "0") break;
    for (int i = 0; i < s.length(); i++) {
      sum += s.c_str()[i] - '0';
    }
    printf("%d\n", sum);
  }

  return 0;
}
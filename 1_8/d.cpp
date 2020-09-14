#include <string>
#include <iostream>
// http://judge.u-aizu.ac.jp/onlinejudge/finder.jsp?course=ITP1
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_8_D

using namespace std;

int main() {
  string s, p;
  int r[100];

  getline(cin, s);
  getline(cin, p);

  string double_s = s + s;

  int pos = double_s.find(p);
  if (pos == std::string::npos) {
    printf("No\n");
  } else {
    printf("Yes\n");
  }

  return 0;
}

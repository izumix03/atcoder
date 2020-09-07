#include <stdio.h>
#include <vector>
// http://judge.u-aizu.ac.jp/onlinejudge/finder.jsp?course=ITP1
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_7_C

using namespace std;

int main() {
  int r = 0, c = 0;
  scanf("%d %d", &r, &c);
  vector<int> sum(c + 1);

  int s;
  int number;
  for (int i = 0; i < r; i++) {
    s = 0;
    for (int j = 0; j < c; j++) {
      scanf("%d", &number);
      sum.at(j) += number;
      s += number;
      printf("%d ", number);
    }
    sum.at(c) += s;
    printf("%d\n", s);
  }

  for (int i = 0; i < c; i++) {
    printf("%d ", sum.at(i));
  }

  printf("%d\n", sum.at(c));
  return 0;
}

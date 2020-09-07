#include <stdio.h>
// http://judge.u-aizu.ac.jp/onlinejudge/finder.jsp?course=ITP1
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_6_B

// ひどい。。
using namespace std;

int main() {
  int n;
  scanf("%d", &n);

  int s[13] = {};
  int h[13] = {};
  int d[13] = {};
  int c[13] = {};

  char mark[2];
  int number;

  for (int i = 0; i < n; i++) {
    scanf("%s %d", &mark, &number);

    if (mark[0] == 'S') s[number-1] = 1;
    if (mark[0] == 'H') h[number-1] = 1;
    if (mark[0] == 'D') d[number-1] = 1;
    if (mark[0] == 'C') c[number-1] = 1;
  }

  for (int i = 0; i < 13; i++) {
    if (s[i] == 0) printf("S %d\n", i+1);
  }

  for (int i = 0; i < 13; i++) {
    if (h[i] == 0) printf("H %d\n", i+1);
  }
  for (int i = 0; i < 13; i++) {
    if (c[i] == 0) printf("C %d\n", i+1);
  }
  for (int i = 0; i < 13; i++) {
    if (d[i] == 0) printf("D %d\n", i+1);
  }

  return 0;
}

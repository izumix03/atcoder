#include <stdio.h>
// http://judge.u-aizu.ac.jp/onlinejudge/finder.jsp?course=ITP1
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_7_A

using namespace std;
// while trueにして、continueしないでelseでつなげればよかったかも
int main() {
  int m = 0, f = 0, r = 0;
  int sum = 0;

  for (int i = 0; i < 50; i++) {
    scanf("%d %d %d", &m, &f, &r);

    if (m == -1 && f == -1 && r == -1) break;


    if (m == -1 || f == -1) {
      printf("F\n");
      continue;
    }

    sum = m + f;
    if (sum >= 80) {
      printf("A\n");
      continue;
    }

    if (sum >= 65) {
      printf("B\n");
      continue;
    }


    if (sum >= 50) {
      printf("C\n");
      continue;
    }

    if (sum < 30) {
      printf("F\n");
      continue;
    }

    if (r >= 50) {
      printf("C\n");
      continue;
    }
    printf("D\n");
  }

  return 0;
}

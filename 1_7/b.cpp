#include <stdio.h>
// http://judge.u-aizu.ac.jp/onlinejudge/finder.jsp?course=ITP1
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_7_B

using namespace std;

int main() {
  int n = 0, x = 0;

  while (true) {
    int count = 0;
    scanf("%d %d", &n, &x);
    if (n == 0 && x == 0) break;

    for (int i = 1; i <= n - 2; i++) {
      if (i > (x / 3 + 1)) break;
      for (int j = i + 1; j <= n - 1; j++) {
        for (int k = j + 1; k <= n; k++) { // このループいらない -> if(x-(min+middle) <= n) count++;
          if ((i + j + k) == x) {
            count++;
            break;
          }
        }
      }
    }
    printf("%d\n", count);
  }

  return 0;
}

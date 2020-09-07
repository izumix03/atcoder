#include <stdio.h>
// http://judge.u-aizu.ac.jp/onlinejudge/finder.jsp?course=ITP1
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_6_A

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int a[n];

  for (int i = 0; i < n; i++) scanf("%d", &a[i]);

  for (int j = n-1; j > 0; j--) printf("%d ", a[j]);

  printf("%d\n", a[0]);
  return 0;
}

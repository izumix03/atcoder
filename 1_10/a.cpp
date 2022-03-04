// http://judge.u-aizu.ac.jp/onlinejudge/finder.jsp?course=ITP1
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_10_A
#include <stdio.h>
#include <cmath>

using namespace std;

void main() {
  double x1, y1, x2, y2;

  scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
  double a;

  a = flg((x1 - x2), 2.0) + flg((y1 - y2), 2.0);
  printf("%.8lf\n", sqrt(a));

  return 0;
}

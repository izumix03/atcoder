// http://judge.u-aizu.ac.jp/onlinejudge/finder.jsp?course=ITP1
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_10_B
#include <stdio.h>
#include <cmath>

using namespace std;

void main() {
  double a, b, degree;

  scanf("%lf %lf %lf", &a, &b, &degree);

  printf("%.8lf\n", (a * b) / 2 * sin(M_PI * degree / 180));
  printf("%.8lf\n", (a + b + sqrt((a * a) + (b * b) - (2 * a * b * cos(M_PI * degree / 180)))));
  printf("%.8lf\n", b * sin(M_PI * degree / 180));

  return 0;
}

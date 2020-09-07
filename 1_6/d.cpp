#include <stdio.h>
#include <vector>
// http://judge.u-aizu.ac.jp/onlinejudge/finder.jsp?course=ITP1
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_6_D

using namespace std;

int main() {
  int n, m = 0;
  scanf("%d %d", &n, &m);

  vector<vector<int>> A(n, vector<int>(m));
  vector<int> b(m);

  int val;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &val);
      A.at(i).at(j) = val;
    }
  }

  for (int j = 0; j<m; j++) {
    scanf("%d", &val);
    b.at(j) = val;
  }

  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum = 0;
    for (int j = 0; j < m; j++) {
      sum += A.at(i).at(j) * b.at(j);
    }
    printf("%d\n", sum);
  }

  return 0;
}

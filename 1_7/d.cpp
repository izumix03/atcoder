#include <stdio.h>
#include <vector>
// http://judge.u-aizu.ac.jp/onlinejudge/finder.jsp?course=ITP1
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_7_D

using namespace std;

int main() {
  int n = 0, m = 0, l = 0;
  scanf("%d %d %d", &n, &m, &l);

  vector<vector<int>> A(n, vector<int>(m));
  vector<vector<int>> B(m, vector<int>(l));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &A.at(i).at(j));
    }
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < l; j++) {
      scanf("%d", &B.at(i).at(j));
    }
  }

  vector<vector<long>> C(n, vector<long>(l));

  for (int i = 0; i < n; i++) {
    for (int k = 0; k < l; k++) {
      for (int j = 0; j < m; j++) {
        C.at(i).at(k) += A.at(i).at(j) * B.at(j).at(k);
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < l - 1; j++) {
      printf("%ld ", C.at(i).at(j));
    }
    printf("%ld\n", C.at(i).at(l - 1));
  }

  return 0;
}

#include <stdio.h>
#include <vector>
// http://judge.u-aizu.ac.jp/onlinejudge/finder.jsp?course=ITP1
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_6_C

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  // building -> floor -> room
  vector<vector<vector<int>>> data(4, vector<vector<int>>(3, vector<int>(10)));

  int building, floor, room, number;

  for (int i = 0; i < n; i++) {
    scanf("%d %d %d %d", &building, &floor, &room, &number);
    data.at(building - 1).at(floor - 1).at(room - 1) += number;
  }

  for (int i = 0; i < 4; i++) {
    if (i != 0) printf("####################\n");
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 10; k++) {
        printf(" %d", data.at(i).at(j).at(k));
        if (k == 9) {
          printf("\n");
        }
      }
    }
  }

  return 0;
}

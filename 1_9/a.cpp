#include <stdio.h>
// http://judge.u-aizu.ac.jp/onlinejudge/finder.jsp?course=ITP1
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_9_C

using namespace std;

int main() {
  int n;
  scanf("%d", &n);

  char taro_card[101], hanako_card[101];
  int taro = 0, hanako = 0;

  for (int i = 1; i <= n; i++) {
    scanf("%s %s", taro_card, hanako_card);

    for (int j = 0; taro_card[j] != '\0'; j++) {
      if (hanako_card[j] > taro_card[j]) {
        hanako += 3;
        break;
      }
      if (hanako_card[j] < taro_card[j]) {
        taro += 3;
        break;
      }

      if (taro_card[j+1] == '\0' && hanako_card[j+1] == '\0') {
        taro++;
        hanako++;
        break;
      }

      if (taro_card[j+1] == '\0') {
        hanako += 3;
        break;
      }

      if (hanako_card[j] == '\0') {
        taro += 3;
        break;
      }
    }
  }
  printf("%d %d\n", taro, hanako);
  return 0;
}

#include <stdio.h>
#include <cctype>
// http://judge.u-aizu.ac.jp/onlinejudge/finder.jsp?course=ITP1
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_8_A

using namespace std;

int main() {
  char ch;

  while ((ch = getchar()) != '\n') {
    if (isupper(ch)) {
      printf("%c", tolower(ch));
    } else if (islower(ch)) {
      printf("%c", toupper(ch));
    } else {
      printf("%c", ch);
    }
  }
  printf("\n");

  return 0;
}
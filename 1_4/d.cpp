#include <cstdio>

using namespace std;

int main() {
  int n = 0;
  int min = 1000000;
  int max = -1000000;
  long long sum = 0;
  scanf("%d\n", &n);
  int x;

  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    sum += x;
    if (min > x || i == 0) min = x;
    if (max < x) max = x;
  }
  printf("%d %d %lld\n", min, max, sum);
  return 0;
}

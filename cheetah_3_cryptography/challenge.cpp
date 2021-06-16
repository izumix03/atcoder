#include <cstdio>
#include <algorithm>
typedef typedef long long ll;

// ■ 暗号
// 1つの数字を選択
// ⇛インクリメント
// 積を最大化する
void solve1() {
  int numbers[] = {1000, 999, 998, 997, 995, 995};

//  int *min_number = std::min_element(std::begin(numbers), std::end(numbers));
//  printf("%d", *min_number);
//
//  ll ans = 1;
//  int cnt = 0;
//
//  for (int i = 0; i < 6; i++) {
//    int num = numbers[i];
//    printf("num: %d\n", num);
//    if (num == *min_number && cnt ==0) {
//      num++;
//      cnt++;
//    }
//    ans *= num;
//    printf("ans: %lld\n----------\n", ans);
//  }
  std::sort(std::begin(numbers), std::end(numbers));
  ll ans = 1;
  numbers[0]++;

  for (int number : numbers) {
    ans *= number;
  }

  printf("%lld\n", ans);
}

int main() {
  solve1();
  return 0;
}


void pattern1();

int main() {
  pattern1();
  return 0;
}

// ■貪欲法
// 5種類: 1円、5円、10円、50円、100円、500円
// 5種類: C1,  C5, C10, C50,  C100, C500枚
// 少ない枚数で A 円を払いたい。
// 必ず払いきれる。
// 何枚でOKか？
#include <algorithm>

void pattern1() {
  int counts[] = {3, 2, 1, 3, 0, 2};

  int A = 620;
  int ans = 0;

  int values[] = {1, 5, 10, 50, 100, 500};

  // 大きい順に使う
  for (int i = 5; i >= 0; i--) {
    // 割れる数だけ使う、が枚数が制約
    int count = std::min(A / values[i], counts[i]);
    // Aをへらす
    A -= values[i] * count;
    ans += count;
  }

  printf("%d\n", ans);
}

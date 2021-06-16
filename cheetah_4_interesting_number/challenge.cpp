#include <cstdio>
#include <vector>

using namespace std;

int power(int base, int j) {
  int result = 1;
  for (int i = 0; i < j; i++) {
    result *= base;
  }
  return result;
}

bool check(int i, int base) {
  for (int j = 2; j * i < base*base*base; j++) {
    int multi = j * i;
    int result = 0;

    for (int r = 0; multi != 0; r++) {
      result += (multi % base) * power(10, r);
      multi /= base;
    }

    int hundred = result / 100;
    int ten = result / 10 - (hundred * 10);
    int one = result - (hundred * 100) - (ten * 10);

    if ((hundred + ten + one) % i != 0) {
      return false;
    }
  }
  return true;
}

// ■ 暗号
// 基数 base
// x の積の各桁の和が xの倍数、全部あげる
void solve1() {
  int base = 10;

  vector<int> ans;

  for (int i = 2; i < base*base*base; i++) {
    if (check(i, base)) ans.push_back(i);
  }

  for (int a : ans) {
    printf("%d\n", a);
  }
}

void solve2() {
  int base = 9;

  vector<int> ans;

  for (int i = 2; i < base*base*base/2; i++) {
    if (check(i, base)) ans.push_back(i);
  }

  for (int a : ans) {
    printf("%d\n", a);
  }
}

int main() {
//  solve1();
  solve2();
  return 0;
}


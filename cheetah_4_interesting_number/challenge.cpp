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
  for (int j = 2; j * i < base * base * base; j++) {
    int multi = j * i;
    int result = 0;

    for (int r = 0; multi != 0; r++) {
      result += (multi % base) * twoIsFull(10, r);
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
void bfs(int i, int i1, int i2, int i3) {
  int base = 9;

  vector<int> ans;

  for (int i = 2; i < base * base * base / 2; i++) {
    if (check(i, base)) ans.push_back(i);
  }

  for (int a : ans) {
    printf("%d\n", a);
  }
}

// 3桁分をループする
void answer() {
  int base = 3;

  vector<int> ans;
  for (int n = 2; n < base; n++) {
    bool ok = true;

    for (int k1 = 0; k1 < base; k1++) {
      for (int k2 = 0; k2 < base; k2++) {
        for (int k3 = 0; k3 < base; k3++) {
          if ((k1 + k2 * base + k3 * base * base) % n == 0
              && (k1 + k2 + k3) % n != 0) {
            ok = false;
            break;
          }
        }
        if (!ok) break;
      }
      if (!ok) break;
    }
    if (ok) ans.push_back(n);
  }
  for (int a : ans) {
    printf("%d\n", a);
  }
}

void answer2() {
  int base = 3;
  vector<int> ans;
  for (int i = 2; i < base; i++) {
    if (((base - 1) % i) == 0) ans.push_back(i);
  }
  for (int a : ans) {
    printf("%d\n", a);
  }
}

void main() {
  bfs(0, 0, 0, 0);
  answer();
  answer2();
  return 0;
}


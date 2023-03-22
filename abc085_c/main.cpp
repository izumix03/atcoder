#include <iostream>
using namespace std;

/**
 * 10000円、5000円、1000円
 * お札が N 枚
 * 合計 Y 円
 * 嘘の場合は、-1 -1 -1
 * ほんとなら それぞれの枚数を返せ(複数ならどれでもOK)
 * 1 <= N <= 2000
 * 1000 <= Y <= 2,000,000
 * @return
 */
int main() {
  int N;
  int Y;
  cin >> N >> Y;

  for (int i = N; i >= 0; i--) {
    if (10000*i > Y) continue;
    for (int j = N - i; j >= 0; j--) {
      if ((10000*i) + (5000*j) + (1000*(N-i-j)) == Y) {
        cout << i << " " << j << " "  << N-i-j << endl;
        return 0;
      }
    }
  }
  cout << "-1 -1 -1" << endl;
  return 0;
}


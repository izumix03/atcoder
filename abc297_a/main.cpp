#include <iostream>
using namespace std;

/**
 * 時刻0でパソコンの電源
 * N回クリック
 *   1 <= i <= N
 *   時刻Ti
 * 時刻x1, x2に連続してクリック
 * x2 - x1 <= D ならば成立
 * 最初に成立した時刻を求めろ
 * 0回なら -1
 *
 * 1 <= N <= 100
 * 1 <= D <= 10^9
 * 1 <= Ti <= 10^9
 * Ti < Ti+1
 * @return
 */
int T[100];
int main() {
  int N;
  int D;
  cin >> N >> D;

  for (int i = 0; i < N; i++) {
    cin >> T[i];
  }

  for (int i = 1; i < N; i++) {
    if (T[i] - T[i-1] <= D) {
      cout << T[i] << endl;
      return 0;
    }
  }

  cout << -1 << endl;
  return 0;
}


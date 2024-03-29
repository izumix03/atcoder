#include <iostream>
#include <vector>
using namespace std;

/**
 * N枚カード
 * i枚目には ai
 * 交互にカードを取得、Aliceが先に取る
 * 取ったカードの合計が得点、最適な行動を取る
 * AliceはBobより何点多く取る？
 * 1 <= N <= 100
 * 1 <= ai <= 100
 * @return
 */
 int a[100];
int main() {
  int N;

  int alice = 0, bob = 0;

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  sort(a, a+N, greater<>());

  for (int i = 0; i < N; i++) {
    if (i % 2==0){
      alice += a[i];
    } else {
      bob += a[i];
    }
  }

  cout << alice - bob << endl;
  return 0;
}

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int arr[300000] = {-1};
queue<int> q;
/**
 * ☆理解できてない。。
 * A個: 0(0 ~ 100,000)
 * B個: 1(0 ~ 100,000)
 *
 * 全部 1 になれば終了
 *
 * k個: 裏返す枚数(0 ~ 100,000)
 * ☆裏返すものは選択可能
 * 何度裏返してもOK
 *
 * 何回で全部が1になるか？不可能なら-1
 */

void check(int nowZero, int useZero, int k) {
  int nextZero = nowZero + k - 2 * useZero; // できるだけ０を増やす
  if (arr[nextZero] == -1) {
    arr[nextZero] = arr[nowZero] + 1;
    q.push(nextZero);
  }
}

int solve(int a, int b, int k) {
  if (a == 0) return 0;
  if (a + b < k) return -1;
  if (a + b == k && b > 0) return -1;

  for (int i = 0; i <= a + b; i++) arr[i] = -1;

  q.push(a);
  arr[a] = 0;

  while (!q.empty()) {
    int i = q.front();
    q.pop();// i は 0の数
    check(i, max(0, k - (a + b - i)), k); // 0 をできるだけへらす
    check(i, min(i, k), k); // 1をできるだけ増やす
    check(i, min(max((i + 1) / 2, k - ((a + b) - i)), k), k); // kに上から近づける
    check(i, min(max(i / 2, k - ((a + b) - i)), k), k);
  }
  return arr[0];
}

int main() {
  // A, B, K
  cout << solve(3, 0, 3) << endl; // 1
  cout << "answer, 1" << endl;
  cout << solve(4, 0, 3) << endl; // 4
  cout << "answer, 4" << endl;
  cout << solve(4, 1, 3) << endl; // 2
  cout << "answer, 2" << endl;
  cout << solve(3, 2, 5) << endl; // -1
  cout << "answer, -1" << endl;
  cout << solve(100000, 100000, 578) << endl; // 174
  cout << "answer, 174" << endl;
  cout << solve(0, 0, 1) << endl; // 0
  cout << "answer, 0" << endl;
  cout << solve(4, 44, 50) << endl; // -1
  cout << "answer, -1" << endl;

  return 0;
}
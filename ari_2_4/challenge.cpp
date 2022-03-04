#include <cstdio>
#include <queue>

using namespace std;

// ■プライオリティーキューの利用
// 距離: L
// ガソリン: 距離と同じで消費, 初期 P
// 補充地点: i, 数はN個
// iまでの距離: Ai
// 補充量: Bi
// 補充可能量: 無制限
// 最小は何回補充が必要？無理なら-1
int solve1(int L, int P, int N, int A[4], int B[4]) {
  // ゴールを補給地点とする
  A[N] = L;
  B[N] = 0;

  // 補給地点管理キュー
  priority_queue<int> que;

  int ans = 0, pos = 0, tank = P;

  for (int i = 0; i <= N; i++) {
    // 次までの距離
    int distance = A[i] - pos;

    while (tank - distance < 0) {
      if (que.empty()) {
        return -1;
      }
      tank += que.top();
      que.pop();
      ans++;
    }

    tank -= distance;
    pos = A[i];
    que.push(B[i]);
  }
  return ans;
}

void main() {
  int L = 25;
  int P = 10;

  int N = 4;
  int A[] = {10, 14, 20, 21};
  int B[] = {10, 5, 2, 4};

  printf("%d\n", solve1(L, P, N, A, B));
  return 0;
}

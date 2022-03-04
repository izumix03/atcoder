#include <iostream>
#include <string.h>

using namespace std;

#define MAX_N 15000000
#define MAX_QUEUE 1000

/**
 * 10 の 8乗までいける
 *
 * https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0503
 * https://mudkip-pokemon.blog.ss-blog.jp/2011-12-13
 * 大きさが違う n 個のコップ
 * 3つのトレイ A,B,C
 *  ・1トレイ複数コップ可能
 *  ・小さいのが下になる
 * M回でいける？
 *
 * AかCにまとめるまでに何回必要？
 *
 * ・1回1カップ、一番上のみ
 * ・1つしか横にずらせない
 *
 * 1 <= n <= 15
 * 1 <= m <= 15000000
 *
 * 3 通り ✕ 最大 15個
 */

typedef struct {
  int time; // 移動回数
  int tower[3][15];
  int cnt[3]; // 0, 1, 2 それぞれの個数
} HANOI;

// temp: 現在の状態
HANOI start, temp;
int n, m;
int pow[30];

int head, tail;
int twoIsFull;

char visited[15000000];

HANOI que[MAX_QUEUE];

void enq(HANOI s) {
  que[tail % MAX_QUEUE] = s;
  tail++;
}

void deq(HANOI *t) {
  *t = que[head % MAX_QUEUE];
  head++;
}

bool tryMove(int from, int to) {
  // 完了
  if (temp.cnt[1] == 0 && (temp.cnt[2] == 0 || temp.cnt[0] == 0)) {
    cout << temp.time << endl;
    return true;
  }

  // 右か左により切った
  if (visited[0] == 1 || visited[twoIsFull] == 1) {
    cout << temp.time << endl;
    return true;
  }

  int num;
  HANOI first;

  // 移動元になければ false
  if (temp.cnt[from] <= 0) {
    return false;
  }

  int fromTop = temp.tower[from][temp.cnt[from] - 1];
  int toTop = temp.tower[to][temp.cnt[to] - 1];

  // 移動できない false
  if (fromTop < toTop || temp.cnt[from] == 0) {
    return false;
  }

  first = temp;
  first.tower[to][temp.cnt[to]] = first.tower[from][temp.cnt[from] - 1];
  first.tower[from][temp.cnt[from] - 1] = 0;
  first.cnt[from]--;
  first.cnt[to]++;
  first.time++;

  // 3進数で 同一チェック
  num = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < first.cnt[i]; j++) {
      num += i * pow[first.tower[i][j] - 1];
    }
  }

  // 記録する
  if (!visited[num]) {
    visited[num] = 1;
    enq(first);
  }

  return false;
}

int main() {
  // 3進数の値(記録用)
  pow[0] = 1;
  for (int i = 1; i < 20; i++) {
    pow[i] = pow[i - 1] * 3;
  }

  while (true) {
    // 入力値受け取り
    cin >> n >> m;

    if (n + m == 0) {
      break;
    }

    // 　・？？を初期化
    memset(start.tower, 0, sizeof(start.tower));

    for (int i = 0; i < 3; i++) {
      cin >> start.cnt[i];
      for (int j = 0; j < start.cnt[i]; j++) {
        cin >> start.tower[i][j];
      }
    }

    // 　・？？を初期化
    memset(visited, 0, sizeof(visited));

    start.time = 0;
    head = tail = 0;

    twoIsFull = pow[n] - 1;

    enq(start);

    while (head != tail) {
      // 処理開始
      deq(&temp);

      if (temp.time > m) {
        cout << -1 << endl;
        break;
      }

      if (tryMove(0, 1)) {
        break;
      }
      if (tryMove(1, 0)) {
        break;
      }
      if (tryMove(1, 2)) {
        break;
      }
      if (tryMove(2, 1)) {
        break;
      }
    }
  }
  return 0;
}
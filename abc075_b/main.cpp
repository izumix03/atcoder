#include <iostream>
using namespace std;

/**
 * H*W のマス目がある
 * . は空きマス
 * # は爆弾マス
 * マス目は H 個の文字列
 *
 * 爆弾マスが8方向にある場合、. を個数に置き換えろ
 * 1 <= H, W <= 50
 * @return
 */
char M[52][52];

int main() {
  int H = 0, W = 0;
  cin >> H >> W;

  for (int i = 1; i <= H; i++){
    for (int j= 1; j <= W; j++) {
      cin >> M[i][j];
    }
  }

  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      if (M[i][j] == '#') {
        continue;
      }

      int count = 0;
      for (int k = -1; k <= 1; k++) {
        for (int l = -1; l <= 1; l++) {
          if (M[i+k][j+l] == '#') {
            count++;
          }
        }
      }
      M[i][j] = (char)(count + '0');
    }
  }

  for (int i = 1; i <= H; i++){
    for (int j= 1; j <= W; j++) {
      cout << M[i][j];
    }
    cout << endl;
  }
}



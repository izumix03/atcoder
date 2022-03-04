#include <string>
#include <iostream>

using namespace std;

// 赤箱: numRed個
// 青箱: numBlue個
// 赤ボール: numRed個
// 青ボール: numBlue個
//
// ※ 1 <= numRed, numBlue <= 100
// ※ -1000 <= onlyRed, onlyBlue, bothColors <= 1000
//
// ・箱には１つのボールしかおけない
//
// ・赤箱、赤ボールは onlyRed ポイント
// ・青箱、青ボールは onlyBlue ポイント
// ・その他は bothColors ポイント
//
// 合計スコアを最大化しよう

//int solve(int numR, int numB, int R, int B, int both) {
//  int ans = -1000;
//  int count = min(numR,numB);
//
//  for (int i = 0; i <= count; i++) {
//    ans = max(ans, (i*2 * both) + ((numR - i) * R) + ((numB - i) * B));
//  }
//
//  return ans;
//}

int solve(int numR, int numB, int R, int B, int both) {
  if ((R + B) > (both * 2)){
    return R * numR + B * numB;
  }
  return (both * 2 * min(numR, numB)) + (max(R, B) * abs(numR - numB));
}

void main() {
  cout << solve(2, 3, 100, 400, 200) << endl; // 1400
  cout << solve(2, 3, 100, 400, 300) << endl; // 1600
  cout << solve(5, 5, 464, 464, 464) << endl; // 4640
  cout << solve(1, 4, 20, -30, -10) << endl; // -100
  cout << solve(9, 1, -1, -10, 4) << endl; // 0
  return 0;
}
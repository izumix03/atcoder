#include <iostream>
#include <string>

using namespace std;

/**
 * 長さ8 の文字列 S
 * S には K,Q が1文字ずつ含まれる
 * S には R,B,Nがちょうど2文字ずつ含まれる
 * Sは下記条件を満たす？
 *  Sはx,y文字目がBなら、xとyの偶奇が異なる
 *  Kは2つのRの間にある、Sのx,y文字目がR、z文字目がKなら、x < z < y
 *
 * つまり、Bの場所は偶奇が異なる
 * つまり、R → K → R となる → R一回でKが出ると読むと改善できる
 * @return
 */

char S[8];

int main() {
  cin >> S;

  int b[2] = {-1, -1};
  int r[2] = {-1, -1};;
  int k = -1;

  for (int i = 0; i < 8; i++) {
    if (S[i] == 'B') {
      if (b[0] == -1) {
        b[0] = i;
      } else {
        b[1] = i;
      }
      continue;
    }

    if (S[i] == 'R') {
      if (r[0] == -1) {
        r[0] = i;
      } else {
        r[1] = i;
      }
      continue;
    }

    if (S[i] == 'K') {
      k = i;
      continue;
    }
  }

  if (b[0] % 2 == b[1] %2) {
    cout << "No" << endl;
  } else if (k < r[0] || k > r[1]) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }

  return 0;
}


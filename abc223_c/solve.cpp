#include <iostream>
#include <vector>

using namespace std;

void solve(vector<int> a, vector<int> b) {
  // 合計時間を求める
  double time = 0;
  for (int i = 0; i < a.size(); i++) {
    time += a[i] / 1.0 / b[i];
  }

  // 時間を半分にする
  double half = time / 2;

  // 左から時間で距離を計算する
  double len = 0;
  for (int i = 0; i < a.size(); i++) {
    double stickTIme = a[i] / 1.0 / b[i];
    double elapsed = min(half, stickTIme);
    len += elapsed * b[i];
    half -= elapsed;
    if (half == 0) break;
  }
  cout << len << endl;
}

int main() {
  string strN;
  std::getline(std::cin, strN);
  int n = std::stoi(strN);

  vector<int> a;
  vector<int> b;
  for (int i = 0; i < n * 2; i++) {
    string tmp;
    cin >> tmp;

    int tmpN = std::stoi(tmp);
    if (i % 2 == 0) {
      a.push_back(tmpN);
    } else {
      b.push_back(tmpN);
    }
  }
  solve(a, b);
  return 0;
}

/**
 * N 本の導火線を一直線に接着したものがあります。
 * 左から i 本目の導火線は長さが A i cm で、 1 秒あたり B i cm 燃えます。
 * この導火線の左端と右端から同時に火をつけるとき、
 * 2 つの火がぶつかる場所が着火前の導火線の左端から何 cm の地点か求めてください。
 */

/**
*
 string input;
  while( std::getline( std::cin, input ) )
  {
    std::cout << "getline:" << input << std::endl;
  }

  int input;
    while( std::cin >> input )
    {
        std::cout << "cin" << input << std::endl;
    }
*/
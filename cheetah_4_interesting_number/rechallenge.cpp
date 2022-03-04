#include <iostream>
#include <vector>

using namespace std;

/**
 * 基数 base を与えられる
 *
 * 基数の3桁より上は考慮不要
 * @return 積の各桁の和が割り切れる数を全部返せ(0, 1以外)
 */

bool check(int base, int i) {
  for (int j = 2; j * i / base / base / base == 0; j++) {
    int multi = j * i;
    // 基数変換の仕方が分からない...なんかいけた

    int h = multi/base/base;
    int t = (multi - (h*base*base)) / base;
    int o = (multi - (h*base*base) - (t*base));
    int sum = h + t + o;
    if (sum % i != 0) return false;
  }
  return true;
}

void solve(int base) {
  vector<int> result;
  for (int i = 2; i < base; i++) {
    if (check(base, i)) {
      result.push_back(i);
    }
  }

  for (auto j: result) {
    cout << j << ",";
  }
  cout << endl;
}


void main() {
  solve(10); // {3, 9}
  solve(3); // {2}
  solve(9); // {2, 4, 8}
  solve(26); // {5, 25}
  solve(30); // {29}
}
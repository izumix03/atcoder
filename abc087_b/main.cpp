#include <iostream>
using namespace std;

// 各種50枚以内
// 500円、100円、50円
// 50 <= X <= 20000

int main() {
  int a;
  int b;
  int c;
  int x;

  cin >> a >> b >> c >> x;

  int cnt = 0;

  for (int i = 0; i <= a; i++) {
    if (x < (500*i)){
      break;
    }

    for (int j = 0; j <= b; j++){
      if (x < (500*i) + (100*j)){
        break;
      }

      for (int k = 0; k <= c; k++) {
        if (x == (500*i) + (100*j) + (50*k)){
          cnt++;
          break;
        }

        if (x < (500*i) + (100*j) + (50*k)){
          break;
        }
      }
    }
  }
  cout << cnt << endl;

  return 0;
}


#include <iostream>
using namespace std;

/**
 * N個の整数
 *
 * @return
 */
int d[100];
int main() {
  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> d[i];
  }

  sort(d, d+N);

  int result=0;
  for (int i = 1; i <= N; i++) {
    if (d[i] != d[i-1]) {
      result++;
    }
  }
  cout << result << endl;
}


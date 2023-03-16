#include <iostream>
#include <string>
using namespace std;


int sumOfI(int i) {
//  int result = 0;
//  string istr = to_string(i);
//  for (int j = 0; j < istr.length(); j++ ) {
//    result += istr[j] - '0';
//  }
//  return result;
  int result = 0;
  while(i > 0){
    result += i % 10;
    i /= 10;
  }
  return result;
}

// 1 <= N <= 10,000
// 1 <= A <= B <= 36

// N 以下で各桁の和が A 以上 B 以下 を全部足す
int main() {
  int N;
  int A;
  int B;

  cin >> N >> A >> B;

  int sum = 0;

  // TODO
  for (int i = 0; i <= N; i++){
    int s = sumOfI(i);
    if (s >= A && s <= B) {
      sum += i;
    }
  }

  cout << sum << endl;

  return 0;
}

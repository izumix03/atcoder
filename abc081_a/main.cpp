#include <iostream>
using namespace std;

int A[200];

int main() {
  int length;
  cin >> length;


  for (int i = 0; i < length; i++) {
    cin >> A[i];
  }

  int count = 0;
  while(true){
    bool allEven = true;
    for (int i = 0; i < length; i++){
      if (A[i] % 2 == 0) {
        A[i] = A[i] / 2;
      } else {
        allEven = false;
      }
    }
    if (allEven) {
      count++;
    } else {
      break;
    }
  }

  cout << count << endl;
  return 0;
}


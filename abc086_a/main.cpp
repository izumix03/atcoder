#include <iostream>
using namespace std;

int main() {
  int n;
  int m;
  cin >> n >> m;

  if (n % 2 == 0 || m % 2 == 0){
    cout << "Even" << endl;
  } else {
    cout << "Odd" << endl;
  }
  return 0;
}


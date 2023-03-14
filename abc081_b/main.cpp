#include <iostream>
#include <string>
using namespace std;

int main() {
  string line;
  cin >> line;

  int count = 0;

  for (int i = 0; i < 3; i++){
    if (line[i] == '1') count++;
  }
  cout << count << endl;
  return 0;
}


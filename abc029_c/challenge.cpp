#include <string>
#include <iostream>

using namespace std;

char c[] = {'a', 'b', 'c'};

string print(int n, string r) {
  if (n == 0) {
    cout << r << endl;
    return r.erase(r.size() - 1);
  }

  for (char i : c) {
    print(n - 1, r + i);
  }
  return "";
}

int main() {
  int n;
  cin >> n;
  print(n, "");
}
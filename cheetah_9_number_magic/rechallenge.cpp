#include <iostream>
#include <set>
#include <vector>

using namespace std;

// 16 以下の整数
// answer 'Y' or 'N' = ex. "YNYY"
// returns A NUMBER
// Card1 = 1,2,3,4,5,6, 7, 8
// Card2 = 1,2,3,4,9,10,11,12
// Card3 = 1,2,5,6,9,10,13,14
// Card4 = 1,3,5,7,9,11,13,15

vector<int> cards[] = {
    {1, 2, 3, 4, 5, 6,  7,  8},
    {1, 2, 3, 4, 9, 10, 11, 12},
    {1, 2, 5, 6, 9, 10, 13, 14},
    {1, 3, 5, 7, 9, 11, 13, 15}
};

void solve(string input, vector<int> vector) {
  vector<int> result = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
  for (int i = 0; i < input.size(); i++) {
    if (input[i] == 'Y') {
      // 積集合
      set_intersection(
          result.begin(),
          result.end(),
          cards[i].begin(),
          cards[i].end(),
          result.begin());
    } else {
      // 差集合
      set_difference(result.begin(),
                     result.end(),
                     cards[i].begin(),
                     cards[i].end(),
                     result.begin());
    }
  }

  return result[0];
}

int main() {
  cout << solve("YNYY", vector<int>()) << endl; // 5
  cout << solve("YNNN", vector<int>()) << endl; // 8
  cout << solve("NNNN", vector<int>()) << endl; // 16
  cout << solve("YYYY", vector<int>()) << endl; // 1
  cout << solve("NYNY", vector<int>()) << endl; // 11
  return 0;
}
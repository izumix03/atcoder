#include <string>

using namespace std;

// 直属Mgr 複数
// 部下がいないと給料1
// 直接部下の給与合計が給与
// char relations[][] = {
//  {'N', 'Y'},
//  {'N', 'N'}
// }

int salary(string relations[], int i, int memo[]) {
  if (memo[i] != 0) return memo[i];

  for (int j = 0; j < relations[i].size(); j++) {
    if (relations[i][j] == 'Y') {
      memo[i] += salary(relations, j, memo);
    }
  }

  if (memo[i] == 0) memo[i]++;
  return memo[i];
}

int solve(string relations[]) {
  int memo[50] = {0};
  memset(memo, 0, relations->size());

  int total = 0;
  for (int i = 0; i < relations->size(); i++) {
    total += salary(relations, i, memo);
  }
  return total;
}

int main() {
  string relations1[] = {
      "NNNNNN",
      "YNYNNY",
      "YNNNNY",
      "NNNNNN",
      "YNYNNN",
      "YNNYNN"
  };
  printf("%d\n", solve(relations1));

  string relations2[] = {
      "NYNNYN",
      "NNNNNN",
      "NNNNNN",
      "NNYNNN",
      "NNNNNN",
      "NNNYYN"
  };

  printf("%d\n", solve(relations2));


  string relations3[] = {
      "NNNN",
      "NNNN",
      "NNNN",
      "NNNN",
  };

  printf("%d\n", solve(relations3));

  return 0;
}
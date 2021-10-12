#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// 直属Mgr 複数
// 部下がいないと給料 1
// 直接部下の給与合計が給与
// char relations[][] = {
//  {'N', 'Y'},
//  {'N', 'N'}
// }
// 全従業員の合計給与を返せ

int salaries[50] = {0};

int salary(vector<string> relations, int ind) {
  if (salaries[ind] != 0) return salaries[ind];

  string no(relations[ind].size(), 'N');
  if (relations[ind] == no) {
    return salaries[ind] = 1;
  }

  int result = 0;
  for (int i = 0; i < relations[ind].size(); i++) {
    if (relations[ind][i] == 'Y') {
      result += salaries[i] = salary(relations, i);
    }
  }
  return salaries[ind] = result;
}

int solve(const vector<string>& relations) {
  for (int i = 0; i < 50; i++) {
    salaries[i] = 0;
  }

  int result = 0;
  for (int i = 0; i < relations.size(); i++) {
    result += salary(relations, i);
  }

  return result;
}

int main() {
  cout << solve({"NNNNNN",
                 "YNYNNY",
                 "YNNNNY",
                 "NNNNNN",
                 "YNYNNN",
                 "YNNYNN"
                }) << endl; // 17


  cout << solve({"NYNNYN",
                 "NNNNNN",
                 "NNNNNN",
                 "NNYNNN",
                 "NNNNNN",
                 "NNNYYN"}) << endl; // 8


  cout << solve({"NNNN",
                 "NNNN",
                 "NNNN",
                 "NNNN",
                }) << endl; // 4



  cout << solve({"N"}) << endl; // 1


  cout << solve({"NNYN",
                 "NNYN",
                 "NNNN",
                 "NYYN",
                }) << endl; // 5

  return 0;
}
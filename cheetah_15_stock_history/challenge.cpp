#include <string>
#include <iostream>
#include <vector>

using namespace std;

// 初期投資: initialInvestment ドル(0 ~ 10000)
// 毎月: monthlyContribution ドル(0 ~1000)
// どれだけ儲かるか答える(端数は最後に四捨五入)
// string stockPrices[]:  月ごとの各株の値段
//
// ・2 <= stockPrices <= 50
// ・空白区切り、月ごとの値段、区切られている整数の数の個数は同じ
// ・1 ~ 999
//
// ・各月のはじめに株券を購入して良い
// ・最後に持ち株をすべて売る、期間途中で売ることはできない


vector<vector<int>> splitV(vector<string> prices) {
  int len = prices.size();
  vector<vector<int>> result(len, vector<int>(0));

  for (int i = 0; i < len; i++) {

    int first = 0;
    int last = int(prices[i].find_first_of(' '));

    while (first < prices[i].size()) {
      string substr(prices[i], first, last - first);
      result.at(i).push_back(stoi(substr));
      first = last + 1;
      last = int(prices[i].find_first_of(' ', first));

      if (last == string::npos) {
        last = int(prices[i].size());
      }
    }
  }

  return result;
}

int solve(int ini, int month, vector<string> prices) {
  vector<vector<int>> ps = splitV(prices);

  int mCnt = int(ps.size());
  int stockCnt = int(ps[0].size());

  double max = 0, profit = 0;
  double proportion[50] = {0};
  bool buy[50] = {false};

  // 最後から遡りつつ、各月までの最大増加率と
  // 買うべきかどうかを記録する
  for (int i = mCnt - 2; 0 <= i; i--) {
    for (int j = 0; j < stockCnt; j++) {
      double p = 1.0 * ps[mCnt - 1][j] / ps[i][j] - 1; // 増加率を出すために -1
      if (0 < p && max < p) {
        buy[i] = true;
        max = p;
        proportion[i] = p;
      }
    }
  }

  // 最初から初めて、買うべき月に来たら全資金を投資する
  for (int i = 0; i < mCnt; i++) {
    if (buy[i]) {
      profit += ini * proportion[i];
      ini = 0;
    }
    ini += month;
  }

  return (int) round(profit);
}

int main() {
  vector<string> prices = {"10 20 30", "15 24 32"};
  cout << solve(1000, 0, prices) << endl; // 500

  vector<string> prices1 = {"10", "9"};
  cout << solve(1000, 0, prices1) << endl; // 0

  vector<string> prices2 = {"40 50 60",
                            "37 48 55",
                            "100 48 50",
                            "105 48 47",
                            "110 50 52",
                            "110 50 52",
                            "110 51 54",
                            "109 49 53"};
  cout << solve(100, 20, prices2) << endl; // 239

  return 0;
}
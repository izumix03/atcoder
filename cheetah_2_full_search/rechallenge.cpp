#include <iostream>
#include <vector>
#include <map>

using namespace std;

/**
 * 招待友人全員が共通の興味ある話題がある時楽しめる
 * String first: first[i] = iが興味あること
 * String second: second[i] = iが興味あること
 *
 * @return 最大何人共通話題を持てるか？
 */

int solve(const vector<string> &first, const vector<string> &second) {
  map<string, int> result;

  for (const string &f: first) {
    result[f]++;
  }

  for (const string &s: second) {
    result[s]++;
  }

  int r = 0;
  for (const auto & it : result) {
    r = max(r, it.second);
  }

  return r;
}


int main() {
  cout << solve(
      {"fishing", "gardening", "swimming", "fishing"},
      {"hunting", "fishing", "fishing", "biting"}) << endl; // 4
  cout << solve(
      {"variety", "diversity", "loquacity", "courtesy"},
      {"talking", "speaking", "discussion", "meeting"}) << endl; // 1
  cout << solve(
      {"snake", "programming", "cobra", "monty"},
      {"python", "python", "anaconda", "python"}) << endl; // 3
  cout << solve(
      {"t", "o", "p", "c", "o", "d", "e", "r", "s", "i", "n", "g", "l",
       "e", "r", "o", "u", "n", "d", "m", "a", "t", "c", "h", "f", "o",
       "u", "r", "n", "i"},
      {"n", "e", "f", "o", "u", "r", "j", "a", "n", "u", "a", "r", "y",
       "t", "w", "e", "n", "t", "y", "t", "w", "o", "s", "a", "t", "u",
       "r", "d", "a", "y"}) << endl; // 6
}
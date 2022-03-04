#include <cstdio>
#include <vector>
#include <map>

using namespace std;

char first[] = {'t', 'o', 'p', 'c', 'o', 'd', 'e', 'r', 's', 'i', 'n', 'g', 'l',
                'e', 'r', 'o', 'u', 'n', 'd', 'm', 'a', 't', 'c', 'h', 'f', 'o',
                'u', 'r', 'n', 'i'};
char secon[] = {'n', 'e', 'f', 'o', 'u', 'r', 'j', 'a', 'n', 'u', 'a', 'r', 'y',
                't', 'w', 'e', 'n', 't', 'y', 't', 'w', 'o', 's', 'a', 't', 'u',
                'r', 'd', 'a', 'y'};


// ■ full search
// 1人 2つの話題
// first[i], second[i]
// 最大何人招待できるか？
void solve1() {
  map<char, int> dic;

  for (int i = 0; i < sizeof first; i++) {
    if (dic[first[i]]) {
      dic[first[i]]++;
    } else {
      dic[first[i]] = 1;
    }

    if (dic[secon[i]]) {
      dic[secon[i]]++;
    } else {
      dic[secon[i]] = 1;
    }
  }

  int ans = 0;
  map<char, int>::iterator  it;
  for (it = dic.begin(); it != dic.end(); it++) {
    ans = max(ans, it->second);
  }
  printf("%d", ans);
}

void main() {
  solve1();
  return 0;
}


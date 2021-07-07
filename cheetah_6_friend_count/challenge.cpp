#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

// ■ 友達の数を数える
// C - A && C - B then A - B
// MAX = length(friends) -1
//
void solve(vector<string> friends) {
  int ans = 0;

  int friendsLength = int(friends.size());

  // 友達図
  vector<vector<int>> graph(friendsLength, vector<int>());

  // i は本人
  for (int i = 0; i < friendsLength; i++) {
    string person = friends[i];
    for (int j = 0; j < friendsLength; j++) {
      // 友達
      if (person[j] == 'Y') {
        graph.at(i).push_back(j);
      }
    }
  }

  //
  for (int i = 0; i < friendsLength; i++) {
    vector<int> a = graph[i];
    set<int> st(graph[i].begin(), graph[i].end());
    for (int x : a) {
      st.insert(graph[x].begin(), graph[x].end());
    }
    ans = max(ans, int(st.size()) - 1);
  }

  printf("bfs: %d\n", ans);
}

void answer(vector<string> friends) {
  int ans = 0;
  int n = int(friends.size());

  for (int i = 0; i < n; i++) {
    int cnt = 0;

    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      if (friends[i][j] == 'Y') {
        cnt++;
      } else {
        for (int k = 0; k < n; k++) {
          if (friends[j][k] == 'Y'
              && friends[k][i] == 'Y') {
            cnt++;
            break;;
          }
        }
      }
      ans = max(ans, cnt);
    }
  }
  printf("%d\n", ans);
}


int main() {
  vector<string> friends = {"NYY", "YNY", "YYN"};
  solve(friends);
  answer(friends);

  friends = {"NYNNN", "YNYNN", "NYNYN", "NNYNY", "NNNYN"};
  solve(friends);
  answer(friends);

  friends = {
      "NNNNYNNNNN",
      "NNNNYNYYNN",
      "NNNYYYNNNN",
      "NNYNNNNNNN",
      "YYYNNNNNNY",
      "NNYNNNNNYN",
      "NYNNNNNYNN",
      "NYNNNNYNNN",
      "NNNNNYNNNN",
      "NNNNYNNNNN"
  };
  solve(friends);
  answer(friends);

  return 0;
}

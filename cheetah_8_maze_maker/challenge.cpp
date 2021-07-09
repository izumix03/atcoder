#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int maze[50][50];
int steps[50][50];

int maxX;
int maxY;

int INF = 100000;

int sy;
int sx;

vector<int> moveY;
vector<int> moveX;

typedef pair<int, int> P;

int maxCount = 0;

// ■幅優先探索
int solve(string pString[6]) {
  queue<P> q;

  q.push(P(sx, sy));
  steps[sy][sx] = 0;

  while (!q.empty()) {
    P p = q.front();
    q.pop();

    // goal
    for (int i = 0; i < moveX.size(); i++) {
      int nextX = p.second + moveX.at(i);
      int nextY = p.first + moveY.at(i);

      if (0 <= nextX && nextX < maxX &&
          0 <= nextY && nextY < maxY &&
          maze[nextY][nextX] != 0 &&
          steps[nextY][nextX] == INF) {
        q.push(P(nextX, nextY));
        maxCount = max(steps[nextY][nextX] = steps[p.second][p.first] + 1, maxCount);
      }
    }
  }

  return maxCount;
}


void set2() {
  string input[] = {"...", "...", "..."};

  sy = 0;
  sx = 1;

  int my[] = {1, 0, -1, 0, 1, 1, -1, -1};
  int mx[] = {0, 1, 0, -1, 1, -1, 1, -1};

  maxX = int(input[0].size());
  maxY = int(input->size());

  for (int i = 0; i < input->size(); i++) {
    for (int j = 0; j < input[i].size(); j++) {
      if (input[i][j] == '.') {
        maze[i][j] = 1;
      } else {
        maze[i][j] = 0;
      }
      steps[i][j] = INF;
    }
  }

  for (int &i : my) {
    moveY.push_back(i);
  }

  for (int &i : mx) {
    moveX.push_back(i);
  }
}

int main() {
  set2();
  printf("%d\n", solve(nullptr));

  return 0;
}

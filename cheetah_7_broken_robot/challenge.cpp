#include <algorithm>

using namespace std;

int NORTH = 1;
int SOUTH = -1;

int EAST = 1;
int WEST = -1;

double solve(int n, int east, int west, int south, int north) {

  //
}

bool grid[100][100] = {false};
int vx[] = {1, -1, 0, 0};
int vy[] = {0, 0, 1, -1};
double prob[4];

double dfs(int x, int y, int n) {
  if (grid[x][y]) return 0;
  if (n==0) return 1;

  // 来たよ！
  grid[x][y] = true;

  double ret = 0;
  for (int i = 0; i < 4; i ++) {
    ret += dfs(x + vx[i], y + vy[i], n - 1) * prob[i];
  }
  grid[x][y] = false;
  return ret;
}

double answer(int n, int east, int west, int south, int north) {
  prob[0] = east / 100.0;
  prob[1] = west / 100.0;
  prob[2] = south / 100.0;
  prob[3] = north / 100.0;

  return dfs(50, 50, n);
}

int main() {
//  printf("%d\n", solve(1, 25, 25, 25, 25)); // 1.0
  printf("%f\n", answer(2, 25, 25, 25, 25)); // 0.75
//  printf("%d\n",solve(7, 50, 0, 0, 50)); // 1.0
//  printf("%d\n",solve(14, 50, 50, 0, 0)); // 1.220703125E-4
//  printf("%d\n",solve(14, 25, 25, 25, 25)); // 0.008845493197441101

  return 0;
}

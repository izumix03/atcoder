#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> topological_sort(vector<vector<int>> &graph, vector<int> &indegree, int verticesCnt) {
  // 記録用配列 = ソートされた辺たち
  vector <int> sorted_vertices;

  // 入寺数が0の頂点をキューに追加
  queue<int> que;
  for (int i = 0; i < verticesCnt; i++) {
    if (indegree[i] == 0) {
      que.push(i);
    }
  }

  // キューが空になるまで、操作1 ~ 3
  while (!que.empty()) {
    int v = que.front();
    que.pop();

    // 隣接している頂点の入寺数を減らし、0 になればキューに追加
    for (int i = 0; i < graph[v].size(); i++) {
      int u  = graph[v][i];
      indegree[u] -= 1;

    }
  }
}

int main() {
  int verticesCnt, edgeCnt;
  cin >> verticesCnt >> edgeCnt;

  vector<vector<int>> graph(verticesCnt);
  vector<int> indegree(verticesCnt);

  for (int i = 0; i < edgeCnt; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    // 入次数を追加
    indegree[v] += 1;
  }

  return 0;
}

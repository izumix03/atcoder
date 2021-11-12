#include <iostream>
#include <vector>
#include <queue>

using namespace std;
// https://qiita.com/Morifolium/items/6c8f0a188af2f9620db2

vector<int> topological_sort(vector<vector<int>> &graph, vector<int> &indegree, int verticesCnt) {
  // 記録用配列 = ソートされた辺たち
  vector <int> sorted_vertices;

  // 入次数が0の頂点をキューに追加
  priority_queue<int, vector<int>, greater<>> que;
  for (int i = 0; i < verticesCnt; i++) {
    if (indegree[i] == 0) {
      que.push(i);
    }
  }

  // キューが空になるまで、操作1 ~ 3
  while (!que.empty()) {
    int v = que.top();
    que.pop();

    // 隣接している頂点の入寺数を減らし、0 になればキューに追加
    for (int u : graph[v]) {
      indegree[u] -= 1;
      if (indegree[u] == 0) que.push(u);
    }
    // 頂点vを配列の末尾に追加する
    sorted_vertices.push_back(v);
  }

  return sorted_vertices;
}

int main() {
  int verticesCnt, edgeCnt;
  cin >> verticesCnt >> edgeCnt;

  vector<vector<int>> graph(verticesCnt);
  vector<int> indegree(verticesCnt);

  for (int i = 0; i < edgeCnt; i++) {
    int u, v;
    cin >> u >> v;
    graph[u-1].push_back(v-1);
    // 入次数を追加
    indegree[v-1] += 1;
  }

  vector<int> sorted_vertices = topological_sort(graph, indegree, verticesCnt);

  if (sorted_vertices.size() != verticesCnt) {
    cout << -1 << endl;
    return 0;
  }

  for (int i = 0; i < verticesCnt; ++i) {
    cout << sorted_vertices[i] + 1 << (i + 1 == verticesCnt ? '\n' : ' ');
  }

  return 0;
}

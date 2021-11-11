#include <iostream>
#include <vector>
#include <queue>

using namespace std;
// https://qiita.com/Morifolium/items/6c8f0a188af2f9620db2

vector<int> topological_sort(vector<vector<int>> &graph, vector<int> &indegree, int verticesCnt) {
  // 記録用配列 = ソートされた辺たち
  vector <int> sorted_vertices;

  // 入次数が0の頂点をキューに追加
  queue<int> que;
  for (int i = 0; i < verticesCnt; i++) {
    if (indegree[i+1] == 0) {
      que.push(i+1);
    }
  }

  // キューが空になるまで、操作1 ~ 3
  while (!que.empty()) {
    int v = que.front();
    que.pop();
//    cout << v << "hoge" << endl;

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
    graph[u].push_back(v);
    // 入次数を追加
    indegree[v] += 1;
  }

  vector<int> sorted_vertices = topological_sort(graph, indegree, verticesCnt);

  for (int sorted_vertice : sorted_vertices) {
    cout << sorted_vertice << endl;
  }

  return 0;
}

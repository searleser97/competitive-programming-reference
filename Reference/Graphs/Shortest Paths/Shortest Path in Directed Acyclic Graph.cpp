// 10
// s = source
#include "../Topological Sort.cpp"
typedef int T; // sum of costs might overflow
const T inf = 1 << 30;
vector<vector<T>> cost;

void init(int N) {
  init(N); // toposort init()
  cost = vector<vector<T>>(N);
}
// 4
// Assumes Directed Graph
void addEdge(int u, int v, T c) {
  adj[u].push_back(v), cost[u].push_back(c);
}
// 15
// O(N)
vector<T> dagsssp(int s) {
  vector<T> dist(adj.size(), inf);
  dist[s] = 0, toposort(s);
  while (toposorted.size()) {
    int u = toposorted.back();
    toposorted.pop_back();
    for (int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i];
      T d = dist[u] + cost[u][i];
      if (d < dist[v]) dist[v] = d;
    }
  }
  return dist;
}
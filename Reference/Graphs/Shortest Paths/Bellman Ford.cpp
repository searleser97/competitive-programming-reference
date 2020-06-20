// 6
// s = source
// returns {} if there is a negative cost cycle
typedef int T;  // sum of costs might overflow
const T inf = 1 << 30;
vector<vector<int>> adj;
vector<vector<T>> cost;
// 4
void init(int N) {
  adj = vector<vector<int>>(N);
  cost = vector<vector<T>>(N);
}
// 4
// Assumes Directed Graph
void addEdge(int u, int v, T c) {
  adj[u].push_back(v), cost[u].push_back(c);
}
// 16
// O(V * E)
vector<T> bellmanFord(int s) {
  vector<T> dist(adj.size(), inf);
  dist[s] = 0;
  for (int i = 1; i <= adj.size(); i++)
    for (int u = 0; u < adj.size(); u++)
      for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        T d = dist[u] + cost[u][i];
        if (dist[u] != inf && d < dist[v]) {
          if (i == adj.size()) return {};
          dist[v] = d;
        }
      }
  return dist;
}
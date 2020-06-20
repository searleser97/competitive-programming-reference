// 5
// s = source
typedef int T; // sum of costs might overflow
const T inf = 1 << 30;
vector<vector<int>> adj;
vector<vector<T>> cost;
// 4
void init(int N) {
  adj.assign(N, vector<int>());
  cost.assign(N, vector<T>());
}
// 4
// Assumes Directed Graph
void addEdge(int u, int v, T c) {
  adj[u].push_back(v), cost[u].push_back(c);
}
// 17
// O(E)
vector<T> sssp01(int s) {
  vector<T> dist(adj.size(), inf);
  deque<int> q;
  dist[s] = 0, q.push_front(s);
  while (q.size()) {
    int u = q.front(); q.pop_front();
    for (int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i];
      T d = dist[u] + cost[u][i];
      if (d < dist[v])
        cost[u][i] ? q.push_back(v)
                     : q.push_front(v);
    }
  }
  return dist;
}
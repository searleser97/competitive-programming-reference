// 5
// s = source
typedef int T;  // sum of costs might overflow
typedef pair<T, int> DistNode;
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
// 17
// ~ O(E * lg(V))
vector<T> dijkstra(int s) {
  vector<T> dist(adj.size(), inf);
  priority_queue<DistNode> q;
  q.push({0, s}), dist[s] = 0;
  while (q.size()) {
    DistNode top = q.top(); q.pop();
    int u = top.second;
    if (dist[u] < -top.first) continue;
    for (int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i];
      T d = dist[u] + cost[u][i];
      if (d < dist[v]) q.push({-(dist[v] = d), v});
    }
  }
  return dist;
}
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
// 20
// O(V * E)
vector<T> bellmanFordFast(int s) {
  vector<T> dist(adj.size(), inf);
  vector<int> its(adj.size()), inqueue(adj.size());
  queue<int> q;
  q.push(s), dist[s] = 0, its[s] = 1;
  while (!q.empty()) {
    int u = q.front(); q.pop(), inqueue[u] = 0;
    for (int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i];
      T d = dist[u] + cost[u][i];
      if (d < dist[v]) {
        dist[v] = d;
        if (!inqueue[v]++) q.push(v), its[v]++;
        if (its[v] == adj.size()) return {};
      }
    }
  }
  return dist;
}
// 6
// icap = initial capacity, f[u] = flow of u
// adj[u][i] = edge from u to v = adj[u][i]
// cap[u][i] = capacity of edge u->adj[u][i]
// rev[u][i] = index of u in adj[v]
// rev is used to find the corresponding reverse edge
// s = source, t = target
// 4
typedef int T;
vector<vector<int>> adj, rev;
vector<vector<T>> cap;
const T inf = 1 << 30;
// 4
void init(int N) {
  adj = rev = vector<vector<int>>(N);
  cap = vector<vector<T>>(N);
}
// 7
// Assumes Directed Graph
void addEdge(int u, int v, T icap) {
  rev[u].push_back(adj[v].size());
  rev[v].push_back(adj[u].size());
  adj[u].push_back(v), adj[v].push_back(u);
  cap[u].push_back(icap), cap[v].push_back(0);
}
// 29
// O(V * E^2)
T maxFlowMinCut(int s, int t) {
  if (s == t) return inf;
  T maxFlow = 0;
  vector<T> f(adj.size());
  while (true) {
    vector<pair<int, int>> dad(adj.size(), {-1, -1});
    queue<int> q;
    q.push(s), f[s] = inf;
    while (q.size() && dad[t].first == -1) {
      int u = q.front(); q.pop();
      for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (dad[v].first == -1 && cap[u][i]) {
          f[v] = min(f[u], cap[u][i]);
          q.push(v), dad[v] = {u, i};
        }
      }
    }
    if (dad[t].first == -1) break;
    maxFlow += f[t];
    for (int v = t; v != s; v = dad[v].first) {
      auto u = dad[v];
      cap[u.first][u.second] -= f[t];
      cap[v][rev[u.first][u.second]] += f[t];
    }
  }
  return maxFlow;
}
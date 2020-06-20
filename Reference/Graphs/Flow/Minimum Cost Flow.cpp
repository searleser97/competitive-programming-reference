// 7
// icost = initial cost, icap = initial capacity
// adj[u][i] = edge from u to v = adj[u][i]
// cap[u][i] = capacity of edge u->adj[u][i]
// cost[u][i] = cost of edge u->adj[u][i]
// rev[u][i] = index of u in adj[v], s = source
// rev is used to find the corresponding reverse edge
// d = distance vector, f[u] = flow of u, t = target
// 4
typedef int T;
const T inf = 1 << 30;
vector<vector<int>> adj, rev;
vector<vector<T>> cap, cost;
// 4
void init(int N) {
  adj = rev = vector<vector<int>>(N);
  cap = cost = vector<vector<T>>(N);
}
// 8
// Assumes Directed Graph
void addEdge(int u, int v, T icap, T icost) {
  rev[u].push_back(adj[v].size());
  rev[v].push_back(adj[u].size());
  adj[u].push_back(v), adj[v].push_back(u);
  cap[u].push_back(icap), cap[v].push_back(0);
  cost[u].push_back(icost), cost[v].push_back(-icost);
}
// 35
// O(V^2 * E^2)
pair<T, T> minCostFlow(int s, int t, int k = inf) {
  if (s == t) return {k, 0};
  T flow = 0, fcost = 0;
  vector<int> inqueue(adj.size());
  vector<T> f(adj.size());
  while (flow < k) {
    vector<pair<int, int>> dad(adj.size(), {-1, -1});
    vector<T> d(adj.size(), inf);
    vector<int> its(adj.size());
    queue<int> q;
    q.push(s), d[s] = 0, its[s] = 1, f[s] = k - flow;
    while (q.size()) {
      int u = q.front();
      q.pop(), inqueue[u] = 0;
      for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        T dist = d[u] + cost[u][i];
        if (dist < d[v] && cap[u][i]) {
          d[v] = dist, dad[v] = {u, i};
          f[v] = min(f[u], cap[u][i]);
          if (!inqueue[v]++) q.push(v), its[v]++;
          if (its[v] == adj.size()) return {-1, -1};
        }
      }
    }
    if (dad[t].first == -1) break;
    flow += f[t], fcost += f[t] * d[t];
    for (int v = t; v != s; v = dad[v].first) {
      auto u = dad[v];
      cap[u.first][u.second] -= f[t];
      cap[v][rev[u.first][u.second]] += f[t];
    }
  }
  return {flow, fcost};
}
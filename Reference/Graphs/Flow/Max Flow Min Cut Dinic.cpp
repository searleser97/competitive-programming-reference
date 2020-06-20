// 7
// level[a] = level in graph of node a
// pathMinCap = capacity bottleneck for a path (s->t)
// icap = initial capacity, f[u] = flow of u
// adj[u][i] = edge from u to v = adj[u][i]
// cap[u][i] = capacity of edge u->adj[u][i]
// rev[u][i] = index of u in adj[v]
// rev is used to find the corresponding reverse edge
// 5
typedef int T;
const T inf = 1 << 30;
vector<vector<int>> adj, rev;
vector<vector<T>> cap;
vector<int> level;
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
// 17
bool levelGraph(int s, int t) {
  level.assign(adj.size(), 0);
  queue<int> q;
  level[s] = 1, q.push(s);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i];
      if (!level[v] && cap[u][i]) {
        q.push(v);
        level[v] = level[u] + 1;
      }
    }
  }
  return level[t];
}
// 14
T blockingFlow(int u, int t, T pathMinCap) {
  if (u == t) return pathMinCap;
  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i];
    if (level[v] == (level[u] + 1) && cap[u][i])
      if (T pathMaxFlow = blockingFlow(
          v, t, min(pathMinCap, cap[u][i]))) {
        cap[u][i] -= pathMaxFlow;
        cap[v][rev[u][i]] += pathMaxFlow;
        return pathMaxFlow;
      }
  }
  return 0;
}
// 9
// O(V^2 * E)
T maxFlowMinCut(int s, int t) {
  if (s == t) return inf;
  T maxFlow = 0;
  while (levelGraph(s, t))
    while (T flow = blockingFlow(s, t, inf))
      maxFlow += flow;
  return maxFlow;
}
// 3
// indeg0 = indegree 0
vector<vector<int>> adj;
vector<int> indegree, toposorted;
// 4
void init(int n) {
  adj.assign(n, vector<int>());
  indegree.assign(n, 0), toposorted.clear();
}
// 4
void addEdge(int u, int v) {
  adj[u].push_back(v);
  indegree[v]++;
}
// 16
// returns false if there is a cycle
// O(V * lg(V) + E)
bool toposort() {
  set<int> indeg0;
  for (int u = 0; u < adj.size(); u++)
    if (!indegree[u]) indeg0.insert(u);
  int cnt = 0;
  while (indeg0.size()) {
    auto u = indeg0.begin();
    toposorted.push_back(*u);
    for (auto& v : adj[*u])
      if (!--indegree[v]) indeg0.insert(v);
    cnt++, indeg0.erase(u);
  }
  return cnt < adj.size() ? false : true;
}
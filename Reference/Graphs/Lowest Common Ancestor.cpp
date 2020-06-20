// 7
// p = parent
#include "../Ranges/Data Structures/Sparse Table.cpp"
typedef pair<int, int> pairii;
vector<int> firstPos;
vector<pair<int, int>> tour;
vector<vector<int>> adj;
SparseTable<pairii> st;

void init(int N) { adj.assign(N, vector<int>()); }
// 4
void addEdge(int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}
// 10
// O(N)
void eulerTour(int u, int p, int h) {
  firstPos[u] = tour.size();
  tour.push_back({h, u});
  for (int v : adj[u])
    if (v != p) {
      eulerTour(v, u, h + 1);
      tour.push_back({h, u});
    }
}
// 11
// O(N * lg(N))
void preprocess() {
  tour.clear();
  firstPos.assign(adj.size(), -1);
  vector<int> roots = {0};
  for (auto &root : roots) eulerTour(root, -1, 0);
  st = SparseTable<pairii>(
      tour, [](pairii a, pairii b) {
        return a.first < b.first ? a : b;
      });
}
// 6
// O(1)
int lca(int u, int v) {
  int l = min(firstPos[u], firstPos[v]);
  int r = max(firstPos[u], firstPos[v]);
  return st.query(l, r).second;
}
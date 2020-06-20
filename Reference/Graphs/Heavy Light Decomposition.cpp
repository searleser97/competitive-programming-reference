// 6
// p = parent;
#include "../Ranges/Data Structures/Segment Tree Lazy Propagation.cpp"
typedef int T;
vector<vector<int>> adj;
vector<int> p, heavy, depth, root, stPos, vals;
SegmentTree<T> st(0, 0);
// 7
void init(int n) {
  adj.assign(n, vector<int>());
  heavy.assign(n, -1);
  vals.assign(n, 0);
  p = root = stPos = depth = heavy;
  st = SegmentTree<T>(n, 0);
}
// 4
void addEdge(int u, int v, T val) {
  adj[u].push_back(v);
  p[v] = u, vals[v] = val;
}

T F(T a, T b) { return a + b; }
// 13
// O(N)
int dfs(int u) {
  int size = 1, maxSubtree = 0;
  for (int &v : adj[u]) {
    depth[v] = depth[u] + 1;
    int subtree = dfs(v);
    if (subtree > maxSubtree)
      heavy[u] = v, maxSubtree = subtree;
    size += subtree;
  }
  return size;
}
// 10
// O(N)
void initHeavyLight() {
  for (int i = 0; i < adj.size(); i++)
    if (p[i] < 0) dfs(i);
  for (int i = 0, pos = 0; i < adj.size(); i++)
    if (p[i] < 0 || heavy[p[i]] != i)
      for (int j = i; ~j; j = heavy[j])
        st[stPos[j] = pos++] = vals[j], root[j] = i;
  st.build();
}
// 13
// O(lg^2 (N))
template <class Op>
void processPath(int u, int v, Op op) {
  for (; root[u] != root[v]; v = p[root[v]]) {
    if (depth[root[u]] > depth[root[v]]) swap(u, v);
    op(stPos[root[v]], stPos[v]);
  }
  if (depth[u] > depth[v]) swap(u, v);
  // for values on edges
  if (u != v) op(stPos[u] + 1, stPos[v]);
  // for values on nodes
  // op(stPos[u], stPos[v]);
}
// 6
// O(lg^2 (N))
void update(int u, int v, T val) {
  processPath(u, v, [&val](int l, int r) {
    st.update(l, r, val);
  });
}
// 8
// O(lg^2 (N))
T query(int u, int v) {
  T ans = T();
  processPath(u, v, [&ans](int l, int r) {
    ans = F(ans, st.query(l, r));
  });
  return ans;
}
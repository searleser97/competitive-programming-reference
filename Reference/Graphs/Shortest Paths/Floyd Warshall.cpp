// 9
// d = distance
typedef int T;  // sum of costs might overflow
const T inf = 1 << 30;
vector<vector<T>> d;

void init(int n) {
  d.assign(n, vector<T>(n, inf));
  for (int i = 0; i < n; i++) d[i][i] = 0;
}
// 2
// Assumes Directed Graph
void addEdge(int u, int v, T c) { d[u][v] = c; }
// 7
// O(V^3)
void floydwarshall() {
  for (int k = 0; k < d.size(); k++)
    for (int u = 0; u < d.size(); u++)
      for (int v = 0; v < d.size(); v++)
        d[u][v] = min(d[u][v], d[u][k] + d[k][v]);
}
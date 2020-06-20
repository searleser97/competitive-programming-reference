// mbm = maximum bipartite matching
#include "Max Flow Min Cut Dinic.cpp"
// 4
void addEdgeMBM(int u, int v) {
  addEdge(u += 2, v += 2, 1);
  addEdge(0, u, 1);
  addEdge(v, 1, 1);
}
// 2
// O(V^2 * E)
T mbm() { return maxFlowMinCut(0, 1); }
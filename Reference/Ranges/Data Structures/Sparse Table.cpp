// 6
// st = sparse table, Arith = Arithmetic
template <class T>
struct SparseTable {
  vector<vector<T>> st;
  function<T(T, T)> F;
  SparseTable() {}
  // 12
  // O(N * lg(N))
  SparseTable(vector<T> &v,
      T f(T, T) = [](T a, T b) { return a + b; })
      : F(f) {
    st.assign(1 + log2(v.size()),
              vector<T>(v.size()));
    st[0] = v;
    for (int i = 1; (1 << i) <= v.size(); i++)
      for (int j = 0; j + (1 << i) <= v.size(); j++)
        st[i][j] = F(st[i - 1][j],
                     st[i - 1][j + (1 << (i - 1))]);
  }
  // 5
  // O(1), [l, r]
  T query(int l, int r) {
    int i = log2(r - l + 1);
    return F(st[i][l], st[i][r + 1 - (1 << i)]);
  }
  // 12
  // O(lg(N)), [l, r]
  T queryArith(int l, int r) {
    T ans = 0; // neutral value
    while (true) {
      int k = log2(r - l + 1);
      ans = F(ans, st[k][l]);
      l += 1 << k;
      if (l > r) break;
    }
    return ans;
  }
};
// 5
// st = segment tree, st[1] = root, H = height of d
// u = updates, d = delayed updates
// neutro = operation neutral val
// e.g. for sum is 0, for multiplication
// is 1, for gcd is 0, for min is INF, etc.
// 7
template <class T>
struct SegmentTree {
  T neutro = 0;
  int N, H;
  vector<T> st, d;
  vector<bool> u;
  function<T(T, T)> F;
  // 5
  SegmentTree(int n, T val,
      T f(T, T) = [](int a, int b) { return a + b; };)
      : st(2 * n, val), d(n), u(n), F(f) {
    H = sizeof(int) * 8 - __builtin_clz(N = n);
  }
  // 7
  void apply(int i, T val, int k) {
    // operation to update st[i] in O(1) time
    st[i] += val * k;  // updates the tree
    // operation to update d[i] in O(1) time
    // which updates values for future updates
    if (i < N) d[i] += val, u[i] = 1;
  }
  // 3
  void calc(int i) {
    if (!u[i]) st[i] = F(st[i << 1], st[i << 1 | 1]);
  }
  // 4
  // O(2N)
  void build() {
    for (int i = N - 1; i; i--) calc(i);
  }
  // 4
  // O(lg(N))
  void build(int p) {
    while (p > 1) p >>= 1, calc(p);
  }
  // 12
  // O(lg(N))
  void push(int p) {
    for (int s = H, k = 1 << (H - 1); s;
         s--, k >>= 1) {
      int i = p >> s;
      if (u[i]) {
        apply(i << 1, d[i], k);
        apply(i << 1 | 1, d[i], k);
        u[i] = 0, d[i] = 0;
      }
    }
  }
  // 10
  // O(lg(N)), [l, r]
  void update(int l, int r, T val) {
    push(l += N), push(r += N);
    int ll = l, rr = r, k = 1;
    for (; l <= r; l >>= 1, r >>= 1, k <<= 1) {
      if (l & 1) apply(l++, val, k);
      if (~r & 1) apply(r--, val, k);
    }
    build(ll), build(rr);
  }
  // 10
  // O(lg(2N)), [l, r]
  T query(int l, int r) {
    push(l += N), push(r += N);
    T ans = neutro;
    for (; l <= r; l >>= 1, r >>= 1) {
      if (l & 1) ans = F(ans, st[l++]);
      if (~r & 1) ans = F(ans, st[r--]);
    }
    return ans;
  }
  // 2
  T& operator[](int i) { return st[i + N]; }
};
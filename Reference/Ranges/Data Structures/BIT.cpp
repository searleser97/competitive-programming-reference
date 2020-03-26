// 7
// 0-indexed
#include "../../BITs Manipulation/Most Significant Set Bit.cpp";

template <class T>
struct BIT {
  T neutro = 0;
  vector<T> bit;
  // 6
  BIT(int n) { bit.assign(++n, neutro); }

  inline T F(T a, T b) {
    return a + b;
    // return a * b;
  }
  // 5
  // Inverse of F
  inline T I(T a, T b) {
    return a - b;
    // return a / b;
  }
  // 7
  // O(N)
  void build() {
    for (int i = 1; i < bit.size(); i++) {
      int j = i + (i & -i);
      if (j < bit.size()) bit[j] = F(bit[j], bit[i]);
    }
  }
  // 4
  // O(lg(N))
  void update(int i, T val) {
    for (i++; i < bit.size(); i += i & -i)
      bit[i] = F(bit[i], val);
  }
  // 6
  // O(lg(N))
  T query(int i) {
    T ans = neutro;
    for (i++; i; i -= i & -i) ans = F(ans, bit[i]);
    return ans;
  }
  // 6
  // O(lg(N)), [l, r]
  T query(int l, int r) {
    return I(query(r), query(--l));
  }
  // 10
  // O(lg(N)) binary search in prefix sum array
  T lowerBound(T x) {
    T acum = neutro;
    int pos = 0;
    for (int i = msb(bit.size() - 1); i; i >>= 1)
      if ((pos | i) < bit.size() &&
          F(acum, bit[pos | i]) < x)
        acum = F(acum, bit[pos |= i]);
    return pos;
  }

  T& operator[](int i) { return bit[++i]; }
};
// 8
// O(m)
vector<int> modinvs(int m) {
  vector<int> inv(m);
  inv[1] = 1;
  for (int i = 2; i < m; i++)
    inv[i] = (m - (m / i) * inv[m % i] % m) % m;
  return inv;
}
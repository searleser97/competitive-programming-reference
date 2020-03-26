// 12
// O(min(|a|, |b|)) -1: a < b, 0: a == b, 1: a > b
int comp(string &a, string &b) {
  int ans = -1, same = 1;
  for (int i = 0; i < min(a.size(), b.size()); i++) {
    if (a[i] != b[i]) same = 0;
    if (a[i] > b[i]) ans = 1;
  }
  if (same)
    ans = a.size() < b.size() ? -1
                              : a.size() > b.size();
  return ans;
}
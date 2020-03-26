// 7
// O(log(n)) [msb, ..., lsb]
int toBase10(vector<int>& n, int b) {
  int ans = 0;
  for (int i = n.size() - 1, p = 1; ~i; i--, p *= b)
    ans += n[i] * p;
  return ans;
}
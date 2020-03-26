// 7
// O(log(n)) [msb, ..., lsb]
vector<int> toBaseB(int n, int b) {
  vector<int> ans;
  while (n) ans.push_back(n % b), n /= b;
  reverse(ans.begin(), ans.end());
  return ans;
}
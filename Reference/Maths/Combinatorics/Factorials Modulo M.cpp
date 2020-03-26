// 9
typedef long long int li;

vector<li> factorials(int n, li m) {
  vector<li> fact(++n);
  fact[0] = 1;
  for (int i = 1; i < n; i++)
    fact[i] = fact[i - 1] * i % m;
  return fact;
}
// 12
typedef long long int li;

vector<vector<li>> nCk(int maxN) {
  vector<vector<li>> c(++maxN, vector<li>(maxN));
  c[0][0] = 1;
  for (int n = 1; n < maxN; n++) {
    c[n][0] = c[n][n] = 1;
    for (int k = 1; k < n; k++)
      c[n][k] = c[n - 1][k - 1] + c[n - 1][k];
  }
  return c;
}
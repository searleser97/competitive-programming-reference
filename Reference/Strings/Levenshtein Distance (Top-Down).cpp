// 12
// i and j are last indexes of s and t respectively
int editDistanceI(string& s, string& t, int i, int j,
                 vector<vector<int>>& dp) {
  if (i < 0) return j + 1;
  if (j < 0) return i + 1;
  if (dp[i][j] != -1) return dp[i][j];
  int replace = editDistance(s, t, i - 1, j - 1, dp);
  int insert = editDistance(s, t, i, j - 1, dp);
  int remove = editDistance(s, t, i - 1, j, dp);
  return dp[i][j] = min(replace + (s[i] != t[j]),
                        min(insert, remove) + 1);
}
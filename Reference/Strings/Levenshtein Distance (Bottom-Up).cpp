// 12
int editDistance(string& s, string& t) {
  vector<vector<int>> dp(t.size() + 1,
                         vector<int>(s.size() + 1));
  for (int i = 1; i <= s.size(); i++) dp[0][i] = i;
  for (int i = 1; i <= t.size(); i++) dp[i][0] = i;
  for (int i = 0; i < t.size(); i++)
    for (int j = 0; j < s.size(); j++)
      dp[i + 1][j + 1] =
          min(dp[i][j] + (t[i] != s[j]),
              min(dp[i][j + 1], dp[i + 1][j]) + 1);
  return dp[t.size()][s.size()];
}
// 13
// O(2^n)
vector<vector<int>> allSubsets(vector<int>& nums) {
  vector<vector<int>> ans;
  int limit = 1 << nums.size();
  for (int i = 0; i < limit; i++) {
    vector<int> aux;
    for (int j = 0; j < nums.size(); j++) {
      if (i & (1 << j)) aux.push_back(nums[j]);
    }
    ans.push_back(aux);
  }
  return ans;
}
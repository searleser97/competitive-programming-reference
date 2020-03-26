// 11
#include "../../Ranges/Data Structures/BIT.cpp"

li invCount(vector<li>& v) {
  BIT<int> bit(*max_element(v.begin(), v.end()) + 1);
  li ans = 0;
  rep(i, v.size()) {
    ans += i - bit.query(v[i]);
    bit.update(v[i], 1);
  }
  return ans;
}
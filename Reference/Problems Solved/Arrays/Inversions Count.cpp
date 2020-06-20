// 9
typedef long long int li;
#include "../../Ranges/Data Structures/BIT.cpp"

li invCount(vector<li>& v, li ans = 0) {
  BIT<int> bit(*max_element(v.begin(), v.end()) + 1);
  for (int i = 0; i < v.size(); i++)
    ans += i - bit.query(v[i]), bit.update(v[i], 1);
  return ans;
}
// 6
li invCount2(vector<li>& v, li ans = 0) {
  BIT<int> bit(*max_element(v.begin(), v.end()) + 1);
  for (int i = v.size() - 1; ~i; i--)
    ans += bit.query(v[i] - 1), bit.update(v[i], 1);
  return ans;
}
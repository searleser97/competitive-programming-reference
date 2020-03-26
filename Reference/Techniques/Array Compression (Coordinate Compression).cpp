// 13
// c = compressed
unordered_map<T, int> Map;
unordered_map<int, T> imap;

template <class T> // don't pass n as param
vector<int> compress(vector<T>& v, int n = 0) {
  set<T> s(v.begin(), v.end());
  vector<int> c(v.size());
  for (auto& e : s) Map[e] = n++;
  for (int i = 0; i < v.size(); i++)
    c[i] = Map[v[i]], imap[c[i]] = v[i];
  return c;
}
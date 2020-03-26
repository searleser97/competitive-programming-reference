// 2
typedef pair<double, double> Interval;
vector<Interval> maxIntervals;
// 23
// O(N * lg(N))
int maxOverlap(vector<Interval> &arr) {
  maxIntervals.clear();
  map<double, int> m;
  int maxI = 0, curr = 0, isFirst = 1;
  double l = -1, r = -1;
  for (auto &i : arr) m[i.first]++, m[i.second + 0.1]--;
  for (auto &p : m) {
    curr += p.second;
    if (curr > maxI) maxI = curr, l = p.first;
    if (curr == maxI) r = p.first;
  }
  curr = 0;
  for (auto &p : m) {
    curr += p.second;
    if (curr == maxI && isFirst)
      l = p.first, isFirst = 0;
    if (curr < maxI && !isFirst)
      maxIntervals.push_back({l, p.first - 1}),
          isFirst = 1;
  }
  return maxI;
}
// 23
// O(MaxPoint) maxPoint < vector::max_size
int maxOverlap(vector<Interval> &arr) {
  maxIntervals.clear();
  T maxPoint = 0;
  for (auto &i : arr)
    if (i.second > maxPoint) maxPoint = i.second;
  vector<int> x(maxPoint + 2);
  for (auto &i : arr) x[i.first]++, x[i.second + 1]--;
  int maxI = 0, curr = 0, isFirst = 1;
  T l = -1LL, r = -1LL;
  for (int i = 0; i < x.size(); i++) {
    curr += x[i];
    if (curr > maxI) maxI = curr;
  }
  curr = 0;
  for (int i = 0; i < x.size(); i++) {
    curr += x[i];
    if (curr == maxI && isFirst) l = i, isFirst = 0;
    if (curr < maxI && !isFirst)
      maxIntervals.push_back({l, i - 1}), isFirst = 1;
  }
  return maxI;
}
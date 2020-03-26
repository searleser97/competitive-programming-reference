// 13
#include "Data Structures/Suffix Automaton.cpp"

// O(N)
string smallestCyclicShift(const string& s) {
  SuffixAutomaton sa(s + s);
  int k = s.size(), u = 0;
  string ans;
  while(k) {
    auto &v = *sa.next[u].begin();
    ans += v.first, u = v.second, k--;
  }
  return ans;
}
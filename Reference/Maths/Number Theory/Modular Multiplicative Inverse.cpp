// 10
// n = number, m = modulo
#include "Extended Euclidean Algorithm.cpp"

// O(lg(N))
li modInv(li n, li m) {
  li g, x, y;
  tie(g, x, y) = extendedGCD(n, m);
  if (g != 1) throw "No solution";
  return (x % m + m) % m;
}
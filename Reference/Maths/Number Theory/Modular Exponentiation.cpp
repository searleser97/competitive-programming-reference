// 9
#include "./Modular Multiplication.cpp"

// O(lg(p))
li pow(li a, li p, li m) {
  li ans = 1;
  for (a %= m; p; a = multiply(a, a, m), p >>= 1)
    if (p & 1LL) ans = multiply(ans, a, m);
  return ans;
}
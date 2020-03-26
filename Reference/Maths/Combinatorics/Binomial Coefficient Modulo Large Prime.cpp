// 10
#include "../Number Theory/Modular Multiplicative Inverse.cpp"
#include "Factorials Modulo M.cpp"

typedef long long int li;

// O(lg(p))
li nCk(int n, int k, li p, vector<li> &fact) {
  return fact[n] * modInv(fact[k], p) % p *
         modInv(fact[n - k], p) % p;
}
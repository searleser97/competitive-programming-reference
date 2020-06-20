// 15
#include "Primes Sieve.cpp"

typedef map<int, int> Map;

// O(lg(N)) n <= sieve.size()
Map getPrimeFactors(int n) {
  Map pf;
  while (n > 1) {
    int p = n & 1 ? sieve[n] : 2, c = 0;
    if (!p) p = n;
    while (n % p == 0) n /= p, c++;
    pf[p] = c;
  }
  return pf;
}
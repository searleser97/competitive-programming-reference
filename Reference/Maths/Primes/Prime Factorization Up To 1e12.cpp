// 17
#include "Primes Sieve.cpp"

typedef long long int li;
typedef map<li, int> Map;

// O(#Primes * lg(N)), n <= sieve.size() ^ 2
Map getPrimeFactors(li n) {
  Map pf;
  for (int& p : primes) {
    if (p * p > n) break;
    int c = 0;
    while (n % p == 0) n /= p, c++;
    if (c) pf[p] = c;
  }
  if (n > 1) pf[n] = 1;
  return pf;
}
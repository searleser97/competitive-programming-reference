// 11
typedef long long int li;

// O(lg(b))
li multiply(li a, li b, li m) {
  li ans = 0;
  for (a %= m; b;
       b >>= 1, a <<= 1, a = (a < m ? a : a - m))
    if (b & 1)
      ans += a, ans = (ans < m ? ans : ans - m);
  return ans;
}
// 9
typedef long long int li;

// O(k)
li nCk(li n, int k) {
  double ans = 1;
  for (int i = 1; i <= k; i++)
    ans = ans * (n - k + i) / i;
  return (li)(ans + 0.01);
}
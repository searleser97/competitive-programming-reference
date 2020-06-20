// 21
int main() {
  long long int x;
  cin >> x;
  auto divs = getDivisors(2 * x);
  int cnt = 0;
  auto check = [&](long long int a, long long int b) {
    long long int r = a - 1;
    if (r < 1 or (b - r) % 2 != 0) return false;
    long long int d = (b - r) / 2;
    if (d <= 0) return false;
    for (int i = 0; i <= r; i++)
      cout << d + i << " \n"[i == r];
    return true;
  };
  for (int i = 1; i < (int)divs.size(); i += 2) {
    long long int a = divs[i - 1], b = divs[i];
    if (check(a, b)) cnt++;
    if (check(b, a)) cnt++;
  }
  cout << cnt << endl;
}
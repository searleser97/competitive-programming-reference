// 3
int msb(int n) {
  return 1 << (sizeof(n) * 8 - __builtin_clz(n) - 1);
}
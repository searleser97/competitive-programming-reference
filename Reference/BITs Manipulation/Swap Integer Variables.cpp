// 5
void swap(int &a, int &b) {
  a ^= b;
  b ^= a;
  a ^= b;
}
// 4
int main() {
  auto comp = [](int x, int y) { return x < y; };
  set<int, decltype(comp)> myset(comp);
}
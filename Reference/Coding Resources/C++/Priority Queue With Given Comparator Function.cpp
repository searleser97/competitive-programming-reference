// 3
struct Object {
  int x, y;
};
// 7
int main() {
  auto cmp = [](const Object& a, const Object& b) {
    return a.x > b.x;
  };
  priority_queue<Object, vector<Object>,
                 decltype(cmp)> pq(cmp);
}
// 10
template <class K, class V>
struct Treap {
  struct Node {
    Node *l = nullptr, *r = nullptr;  // left, right
    K key;
    V val;
    int prior, sz = 1;
    Node(K k, V v, int p = rand())
        : key(k), val(v), prior(p) {}
  };
  // 2
  Treap() {}
  Node *root = nullptr;
  // 9
  // O(lg(N))
  V get(K key) {
    Node *t = root;
    while (t)
      if (key == t->key) return t->val;
      else if (key < t->key) t = t->l;
      else t = t->r;
    throw runtime_error("Treap: Key doesn't exist");
  }
  // 7
  // O(1)
  void updateSize(Node *t) {
    if (!t) return;
    t->sz = 1;
    if (t->l) t->sz += t->l->sz;
    if (t->r) t->sz += t->r->sz;
  }
  // 11
  // O(lg(N)), first <= key < second
  pair<Node *, Node *> split(Node *t, K key) {
    if (!t) return {NULL, NULL};
    Node *left, *right;
    if (key < t->key)
      tie(left, t->l) = split(t->l, key), right = t;
    else
      tie(t->r, right) = split(t->r, key), left = t;
    updateSize(t);
    return {left, right};
  }
  // 8
  // O(lg(N))
  void insert(Node *&t, Node *v) {
    if (!t) t = v;
    else if (v->prior > t->prior)
      tie(v->l, v->r) = split(t, v->key), t = v;
    else insert(v->key < t->key ? t->l : t->r, v);
    updateSize(t);
  }
  // 4
  // O(lg(N))
  void insert(K key, V val) {
    insert(root, new Node(key, val));
  }
  // 10
  // O(lg(N)) asumes a.keys < b.keys
  Node *merge(Node *a, Node *b) {
    Node *ans;
    if (!a || !b) ans = a ? a : b;
    else if (a->prior > b->prior)
      a->r = merge(a->r, b), ans = a;
    else b->l = merge(a, b->l), ans = b;
    updateSize(ans);
    return ans;
  }
  // 7
  // O(lg(N))
  void erase(Node *&t, K key) {
    if (!t) return;
    if (t->key == key) t = merge(t->l, t->r);
    else erase(key < t->key ? t->l : t->r, key);
    updateSize(t);
  }
  // 2
  // O(lg(N))
  void erase(K key) { erase(root, key); }
  // 11
  // O(lg(N)) 1-indexed (k-th smallest)
  K kth(int k) {
    Node *t = root;
    while (t) {
      int sz = t->l ? t->l->sz : 0;
      if (sz + 1 == k) return t->key;
      else if (k > sz) t = t->r, k -= sz + 1;
      else t = t->l;
    }
    throw runtime_error("Treap: Index out of bounds");
  }
  // 10
  // O(M * lg(N / M))
  Node *join(Node *a, Node *b) {
    if (!a || !b) return a ? a : b;
    if (a->prior < b->prior) swap(a, b);
    Node *l, *r;
    tie(l, r) = split(b, a->key);
    a->l = join(a->l, l), a->r = join(a->r, r);
    updateSize(a);
    return a;
  }
  // 3
  void join(Treap<K, V> t) {
    root = join(root, t.root);
  }
  // 7
  // O(N)
  Node *copy(Node *t) {
    if (!t) return nullptr;
    Node *x = new Node(t->key, t->val, t->prior);
    x->l = copy(t->l), x->r = copy(t->r);
    return x;
  }
  // 10
  void print(string s, Node *t, bool isleft) {
    if (!t) return;
    cout << s << (isleft ? "|__" : "\\__");
    cout << t->val << "~" << t->prior << endl;
    print(s + (isleft ? "|   " : "    "), t->l, 1);
    print(s + (isleft ? "|   " : "    "), t->r, 0);
  }

  void print() { print("", root, false); }
};
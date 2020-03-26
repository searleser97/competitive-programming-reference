// 11
template <class K, class V>
struct RedBlackTree {
  struct Node {
    K key;
    V val;
    Node *l = nullptr, *r = nullptr;  // left, right
    bool isRed;
    Node(K k, V v, bool isRed)
        : key(k), val(v), isRed(isRed) {}
  };

  Node *root = nullptr;
  
  int compare(K a, K b) { return a < b ? -1 : a > b; }
  // 9
  // O(lg(N))
  V get(K key) {
    Node *t = root;
    while (t)
      if (key == t->key) return t->val;
      else if (key < t->key) t = t->l;
      else t = t->r;
    throw "Key doesn't exist";
  }
  // 8
  Node *rotateLeft(Node *t) {
    Node *x = t->r;
    t->r = x->l;
    x->l = t;
    x->isRed = t->isRed;
    t->isRed = 1;
    return x;
  }
  // 8
  Node *rotateRight(Node *t) {
    Node *x = t->l;
    t->l = x->r;
    x->r = t;
    x->isRed = t->isRed;
    t->isRed = 1;
    return x;
  }
  // 5
  void flipColors(Node *t) {
    t->isRed = 1;
    t->l->isRed = 0;
    t->r->isRed = 0;
  }
  // 16
  // O(lg(N))
  Node *insert(Node *t, K key, V val) {
    if (!t) return new Node(key, val, 1);
    int cmp = compare(key, t->key);
    if (!cmp) t->val = val;
    if (cmp < 0) t->l = insert(t->l, key, val);
    if (cmp > 0) t->r = insert(t->r, key, val);
    if (t->r && t->r->isRed && !(t->l && t->l->isRed))
      t = rotateLeft(t);
    if (t->l && t->l->isRed && t->l->l &&
        t->l->l->isRed)
      t = rotateRight(t);
    if (t->l && t->l->isRed && t->r && t->r->isRed)
      flipColors(t);
    return t;
  }
  // 5
  // O(lg(N))
  void insert(K key, V val) {
    root = insert(root, key, val);
  }
};
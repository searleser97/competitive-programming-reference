// 3
// su = sum update, ru = replace update, rev = reverse
// psu = pending sum update, sz = size
// pru = pending replace update
// 8
template <class T>
struct ImplicitTreap {
  struct Node {
    Node *l = nullptr, *r = nullptr;  // left, right
    T val, minim = (1 << 30), sum = 0, su = 0, ru;
    int prior, sz = 1, rev = 0, psu = 0, pru = 0;
    Node(T e, int p = rand()) : val(e), prior(p) {}
  };
  // 2
  ImplicitTreap() {}
  Node *root = nullptr;
  // 13
  // O(1)
  void pull(Node *t) {
    if (!t) return;
    t->sz = 1, t->sum = t->val, t->minim = t->val;
    if (t->l) {
      t->sz += t->l->sz, t->sum += t->l->sum;
      t->minim = min(t->minim, t->l->minim);
    }
    if (t->r) {
      t->sz += t->r->sz, t->sum += t->r->sum;
      t->minim = min(t->minim, t->r->minim);
    }
  }
  // 5
  void applySu(Node *t, T su) {
    if (!t) return;
    t->val += su, t->psu = 1, t->su += su;
    t->sum += su * t->sz, t->minim += su;
  }
  // 4
  void applyRev(Node *t) {
    if (!t) return;
    t->rev ^= 1, swap(t->l, t->r);
  }
  // 5
  void applyRu(Node *t, T ru) {
    if (!t) return;
    t->val = ru, t->pru = 1, t->ru = ru;
    t->sum = ru * t->sz, t->minim = ru;
  }
  // 12
  // O(1)
  void push(Node *t) {
    if (!t) return;
    if (t->psu) {
      applySu(t->l, t->su), applySu(t->r, t->su);
      t->psu = t->su = 0;
    }
    if (t->rev)
      applyRev(t->l), applyRev(t->r), t->rev = 0;
    if (t->pru) {
      applyRu(t->l, t->ru), applyRu(t->r, t->ru);
      t->pru = 0;
    }
  }
  // 16
  // O(lg(N)), first <= idx < second
  pair<Node *, Node *> split(Node *t, int idx,
                             int cnt = 0) {
    if (!t) return {NULL, NULL};
    push(t);
    Node *left, *right;
    int idxt = cnt + (t->l ? t->l->sz : 0);
    if (idx < idxt)
      tie(left, t->l) = split(t->l, idx, cnt),
                right = t;
    else
      tie(t->r, right) = split(t->r, idx, idxt + 1),
                left = t;
    pull(t);
    return {left, right};
  }
  // 11
  // O(lg(N))
  void insert(Node *&t, Node *v, int idxv, int cnt) {
    int idxt = t ? cnt + (t->l ? t->l->sz : 0) : 0;
    push(t);
    if (!t) t = v;
    else if (v->prior > t->prior)
      tie(v->l, v->r) = split(t, idxv, cnt), t = v;
    else if (idxv < idxt) insert(t->l, v, idxv, cnt);
    else insert(t->r, v, idxv, idxt + 1);
    pull(t);
  }
  // 4
  // O(lg(N)), insert element in i-th position
  void insert(T e, int i) {
    insert(root, new Node(e), i - 1, 0);
  }
  // 11
  // O(lg(N)) asumes a.indexes < b.indexes
  Node *merge(Node *a, Node *b) {
    push(a), push(b);
    Node *ans;
    if (!a || !b) ans = a ? a : b;
    else if (a->prior > b->prior)
      a->r = merge(a->r, b), ans = a;
    else b->l = merge(a, b->l), ans = b;
    pull(ans);
    return ans;
  }
  // 10
  // O(lg(N))
  void erase(Node *&t, int idx, int cnt = 0) {
    if (!t) return;
    push(t);
    int idxt = cnt + (t->l ? t->l->sz : 0);
    if (idxt == idx) t = merge(t->l, t->r);
    else if (idx < idxt) erase(t->l, idx, cnt);
    else erase(t->r, idx, idxt + 1);
    pull(t);
  }
  // 2
  // O(lg(N)), erase element at i-th position
  void erase(int i) { erase(root, i); }
  // 4
  // O(lg(N))
  void push_back(T e) {
    root = merge(root, new Node(e));
  }
  // 7
  // O(lg(N))
  void op(int l, int r, function<void(Node *&)> f) {
    Node *a, *b, *c;
    tie(a, b) = split(root, l - 1);
    tie(b, c) = split(b, r - l);
    f(b), root = merge(a, merge(b, c));
  }
  // 4
  // O(lg(N)), reverses [l, ..., r]
  void reverse(int l, int r) {
    op(l, r, [&](Node *&t) { applyRev(t); });
  }
  // 9
  // O(lg(N)), rotates [l, ..., r] k times
  void rotate(int l, int r, int k) {
    op(l, r, [&](Node *&t) {
      Node *l, *r;
      k %= t->sz, tie(l, r) = split(t, t->sz - k - 1);
      t = merge(r, l);
    });
  }
  // 5
  // O(lg(N)), adds val to [l, ..., r]
  void add(int l, int r, T val) {
    op(l, r,
       [&](Node *&t) { applySu(t, val); });
  }
  // 5
  // O(lg(N)), sets val to [l, ..., r]
  void replace(int l, int r, T val) {
    op(l, r,
       [&](Node *&t) { applyRu(t, val); });
  }
  // 6
  // O(lg(N)), minimum in [l, ..., r]
  T getMin(int l, int r) {
    T ans;
    op(l, r, [&](Node *&t) { ans = t->minim; });
    return ans;
  }
  // 6
  // O(lg(N)), sum in [l, ..., r]
  T getSum(int l, int r) {
    T ans;
    op(l, r, [&](Node *&t) { ans = t->sum; });
    return ans;
  }
  // 8
  // O(N)
  void print(Node *t) {
    if (!t) return;
    push(t);
    print(t->l);
    cout << t->val << " ";
    print(t->r);
  }
  // 2
  void print() { print(root), cout << endl; }
};
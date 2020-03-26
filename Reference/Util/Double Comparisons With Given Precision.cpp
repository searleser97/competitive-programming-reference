// 9
typedef long double ld;
const ld eps = 1e-9;

bool eq(ld a, ld b) { return abs(a - b) <= eps; }
bool neq(ld a, ld b) { return abs(a - b) > eps; }
bool gt(ld a, ld b) { return a - b > eps; }
bool lt(ld a, ld b) { return b - a > eps; }
bool gte(ld a, ld b) { return a - b >= -eps; }
bool lte(ld a, ld b) { return b - a >= -eps; }
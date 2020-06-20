// 5
typedef long long int li;

// if m is positive the answer is positive
// if m is negative the answer is negative
li mod(li a, li m) { return (m + (a % m)) % m; }
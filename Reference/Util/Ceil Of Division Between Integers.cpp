// 9
typedef long long int li;

int sign(li x) { return x < 0 ? -1 : x > 0; }

//         a / b
li ceil(li a, li b) {
  if (sign(a) == sign(b) && a % b) return a / b + 1;
  else return a / b;
}
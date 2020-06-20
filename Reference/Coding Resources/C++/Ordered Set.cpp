// 7
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set                            \
  tree<int, null_type, less<int>, rb_tree_tag, \
       tree_order_statistics_node_update>
// 9
int main() {
  vector<int> v = {3, 1, 5, 2};
  ordered_set os(v.begin(), v.end());
  // prints 3 which is the element in index 2
  cout << *(os.find_by_order(2)) << endl;
  // prints 2 which is the number of items
  // strictly smaller than 3
  cout << os.order_of_key(3)  << endl;
}
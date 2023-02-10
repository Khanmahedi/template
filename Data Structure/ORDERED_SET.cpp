#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<pair < ll , ll > , null_type, less<pair <ll , ll > >, rb_tree_tag,
             tree_order_statistics_node_update>
  ordered_set;
  //order_of_key(k) Number of items striclty smaller than k
  //find_by_order(k) K-th element in a set (counting from index zero)

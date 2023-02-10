
// information for a node 
// prefixsum , sufixsum , max_subarray_sum , total_sum ;

#include<bits/stdc++.h>
using namespace std;
#define ll      long long
#define pb      push_back
#define TT ll time;        cin >> time; while(time--)
#define FastIo  ios_base::sync_with_stdio(false);cin.tie(NULL) ;
const ll mod =   998244353  , N = 1e6+10 , INF = 5e18, block = 400 ;
#ifndef ONLINE_JUDGE
#include "algodebug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
ll ar[N] ;

struct SegmentTree{
  vector < ll > tree ;
  SegmentTree(ll n){
    tree.resize(4*n+10) ;
  }
  void build(ll node , ll l , ll r){
    if(l == r){
      tree[node] = ar[l] ;
      return ;
     }
     ll mid = (l + r) / 2 ;
     ll left = node*2 ;
     ll right = node*2 + 1 ;
     build(left , l , mid) ;
     build(right , mid + 1, r) ;
     tree[node] = min(tree[left]  , tree[right]) ;
  }
  
  void Update(ll node , ll b , ll e, ll point , ll val){
    if(b == e and b == point){
      tree[node] = val ; 
      return;
    }
   if(e < point or b > point)
      return;  
    
    ll mid = (b + e) / 2 ;
    ll left = node*2 ;
    ll right = node*2 +1 ;
    
    Update(left , b, mid , point , val) ;
    Update(right , mid +1 , e , point , val) ;
    tree[node] = min(tree[left], tree[right]) ;
  }
  ll query(ll node , ll b, ll e, ll l , ll r){
    if(b > r or e < l) return INF ;
    if(l <= b and r >= e) return tree[node] ;
    ll mid = (b + e)/2 , left = node*2 , right = node*2+1 ;
    ll one = query(left , b , mid , l , r) ;
    ll two = query(right , mid+1, e , l , r) ;
    return min(one, two) ;
  }
};


int main(){
    
    ll n , q ;
    cin >> n >> q ;
    for( ll i = 1 ; i <= n ; i++) cin >> ar[i] ;
    SegmentTree seg(n) ;
    seg.build(1, 1, n) ;


    for( ll i = 0 ; i < q ; i++){
      ll ind , x , y ;
      cin >> ind >> x >> y ;
      if(ind == 1){
      seg.Update(1, 1, n , x , y) ;
    }
    else {
      cout << seg.query(1, 1, n , x , y) << endl ;

    }

    }
}


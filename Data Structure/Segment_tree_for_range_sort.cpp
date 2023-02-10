vector < ll > Tree[N] ; 
ll shuru[200005], siz[200005] ; 
void build(ll node , ll b , ll e){ 
 if(b == e){ 
 Tree[node].push_back(SA[b-1]) ; 
 return ; 
 } 
 ll mid = (b + e) / 2 ; 
 build(node*2, b , mid) ; 
 build(node*2+1, mid +1 , e) ; 
 merge(Tree[node*2].begin(), Tree[node*2].end(), 
Tree[node*2+1].begin(), Tree[node*2+1].end(), 
back_inserter(Tree[node])) ; 
} 
ll Query(ll node , ll b, ll e, ll i , ll j , ll l , ll r){ 
 if(b > j or e < i) return 0 ; 
 if(i <= b and j >= e){ 
 debug(Tree[node]) ; 
 return upper_bound(Tree[node].begin(), Tree[node].end(), 
r) - lower_bound(Tree[node].begin(), Tree[node].end(), l) ; 
 } 
 ll mid = (b + e)/2 ; 
 return Query(node*2, b , mid , i , j , l , r) + Query(node*2 +1 
, mid +1 , e , i , j , l , r) ; 
} 

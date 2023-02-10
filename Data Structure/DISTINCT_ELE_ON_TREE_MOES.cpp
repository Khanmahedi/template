#include<bits/stdc++.h>
using namespace std;
#define ll      long long int
#define pb      push_back
#define T ll time;        cin >> time; while(time--)
#define FastIo  ios_base::sync_with_stdio(false);cin.tie(NULL) ;
const ll mod = 1e9+7  , N = 1e6+100 , INF = 5e17 ;
ll Flat[N] , LCA[50000][25] , Level[N] , Start[N] , End[N] ,  A[N] , timer , Tot = 0 , block = 500;
ll cnt[N] ;
ll ResCnt[N] ;
vector < ll > ad[N] ;
struct Query{
    ll l , r, lca , ind;
}query[N] ;

void addedge(ll a, ll b){
      ad[a].pb(b) ;
      ad[b].pb(a) ;
}
void dfs(ll node , ll par ){
    Flat[++timer] = node ;
    Start[node] = timer ;
    LCA[node][0] = par ;
    for(auto child : ad[node]){
        if(child != par){
        Level[child]+=Level[node] + 1 ;
        dfs(child , node) ;
    }
} 
    Flat[++timer] = node ;
    End[node] = timer ; 
}

void LcaPre(ll n){
    for( ll i = 1 ; i <= 20 ; i++){
        for( ll j = 0 ; j <= n ; j++){
            if(LCA[j][i-1] != -1){
                LCA[j][i] = LCA[LCA[j][i - 1]][i - 1] ;
            }
        }
    }
}
ll Lca(ll a, ll b){
    if(Level[a] < Level[b]) swap(a , b) ;
    ll d = Level[a] - Level[b] ;
    while(d > 0){
        ll k = log2(d) ;
        a = LCA[a][k] ;
        d-=(1ll << k) ;
    }
    if(a == b) return a ;
    
    for( ll i = 20 ; i >= 0 ; i--){
        if(LCA[a][i] != -1 and LCA[a][i] != LCA[b][i]){
            a = LCA[a][i] ;
            b = LCA[b][i] ;
        }
    }
    return LCA[a][0] ; 
}
bool MoSort(Query a , Query b){
    if(a.l/block != b.l/block)
        return a.l/block < b.l/block ;
    return a.r < b.r ;
}
void add(ll l){
    cnt[Flat[l]]++ ;
  if(cnt[Flat[l]] == 1) {
    if(!ResCnt[A[Flat[l]]]) Tot++ ;
    ResCnt[A[Flat[l]]]++ ;
}
else{
    ResCnt[A[Flat[l]]]-- ;
    if(ResCnt[A[Flat[l]]] == 0) Tot-- ;
}
  
}
void remove(ll l){
   cnt[Flat[l]]-- ;
    if(cnt[Flat[l]] == 1){
        if(ResCnt[A[Flat[l]]] == 0) Tot++ ;
        ResCnt[A[Flat[l]]]++ ;
    }
    else{
        ResCnt[A[Flat[l]]]-- ;
        if(ResCnt[A[Flat[l]]] == 0) Tot-- ;
    }

}


int main(){
FastIo ;
ll n , q , x, y , val = 1 ;
cin >> n >> q ;
memset(LCA , -1 , sizeof(LCA)) ;
map < ll , ll > mp ;
vector < ll > ans(q+1) ;
for( ll i = 1 ; i <= n ; i++) {
    cin >> A[i] ;
    if(!mp[A[i]]){
        mp[A[i]] = val ;
        val++ ;
    }
    A[i] = mp[A[i]] ;
}

for( ll i = 0 ; i+1 < n ; i++){
    cin >> x >> y ;
    addedge(x , y) ;
}
Level[1] = 1 ;
timer = 0 ;
dfs(1 , -1) ;
LcaPre(n) ;

for( ll i = 0 ; i < q ; i++){
    cin >> x >> y ;
    if(Start[x] > Start[y]) swap(x , y) ;
    ll p = Lca(x , y) ;
    query[i].ind = i+1 ;
    if(p == x ){
        query[i].l = Start[x] ;
        query[i].r = Start[y] ;
        query[i].lca = -1 ;
    }
    else{
        query[i].l = End[x] ;
        query[i].r = Start[y] ;
        query[i].lca = p ;
    }
}

sort(query, query+q , MoSort) ;
ll L , R, one = 0  ;
L =1, R = 0 ;

for( ll i = 0 ; i < q ; i++){
        while(query[i].l < L) add(--L) ; 
        while(query[i].r > R) add(++R) ;
        while(query[i].l > L) remove(L++) ;
        while(query[i].r < R) remove(R--) ;
        if(query[i].lca != -1){
            if(ResCnt[A[query[i].lca]] == 0) one = 1 ;
        }
        ans[query[i].ind] = Tot + one  ;
        one = 0 ;
}

for( ll i = 1 ; i <= q ; i++)
cout << ans[i] << endl ;






}

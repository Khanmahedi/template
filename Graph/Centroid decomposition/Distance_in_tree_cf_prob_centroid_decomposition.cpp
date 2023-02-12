#include<bits/stdc++.h>
#pragma GCC target("popcnt")
using namespace std;
#define ll       long long
#define pb      push_back
#define TT ll time;        cin >> time; while(time--)
#define FastIo  ios_base::sync_with_stdio(false);cin.tie(NULL) ;
const ll int INF = 5e18 , nmax = 2501 , block = 350 , N = 2e6+20 , mod = 1e9+7;
#ifndef ONLINE_JUDGE
#include "algodebug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
vector < int > g[N] ;
int vis[N] , par[N] , sz[N] , cnt[N]  , n , k  ;
ll sol = 0 , ans = 0 ;
 
int get_size(int u, int p){
    if(vis[u]) return 0 ;
    sz[u] = 1 ;
    for(int v: g[u]){
        if(v == p) continue ;
        sz[u]+=get_size(v, u) ;
    }
    return sz[u] ;
}
 
int get_centroid(int u , int p , int n){
    for(int v: g[u]){
        if(v == p) continue ;
        if(!vis[v] && sz[v] > n/2)
            return get_centroid(v , u ,n) ;
    }
    return u ;
}
void dfs1(int u , int p, int val , bool flag){
     if(flag) cnt[val]++ ;
     else cnt[val]-- ;
     for(int v: g[u]){
        if(v == p or vis[v]) continue ;
        dfs1(v , u , val+1, flag) ;
     }
}
void solve(int u , int p , int val){
   if(val > k) return;
   sol+=cnt[k - val] ;
   for(int v: g[u]){
    if(!vis[v] && v!=p) solve(v, u , val+1) ; 
   }
}
 
void centroid(int u , int p){
    get_size(u, p) ;
    int c = get_centroid(u, p , sz[u]) ;
    sol = 0 ;
    dfs1(c , p , 0 , 1) ;
 
    sol+=cnt[k] ;
 
    for(int X: g[c]){
        if(vis[X]) continue ;
        dfs1(X , c , 1, 0) ;
        solve(X, c , 1) ;
        dfs1(X, c , 1, 1) ;
    }
 
    ans+=sol/2 ;
 
    dfs1(c, p, 0, 0) ;
 
    vis[c] = 1 ;
    for(int v: g[c]){
        if(vis[v]) continue ;
        centroid(v , c) ;
    }
}
 
int main(){
    FastIo ; 
    cin >> n >> k ;
    for(int i = 0 ; i < n - 1 ; i++){
        int u, v ;
        cin >> u >> v ;
        g[u].pb(v) ;
        g[v].pb(u) ;
    }
    centroid(1, -1) ;
    cout << ans << endl ;
    
 
}  

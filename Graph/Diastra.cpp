// priority_queue <pair<ll, ll>, vector< pair<ll, ll> >, 
//greater<pair<ll, ll> > > pq ; 


vector < pair < ll , double > > ad[100000] ; 
 double dijkstra(ll n){ 
 priority_queue < pair < double , ll > > pq ; 
 double dist[100000] ; 
 ll vis[10000] = {} ; 
 for( ll i = 0 ; i < 101 ; i++) dist[i] = -1.0 ; 
 pq.push({1.0, 1}) ; 
 dist[1] = 1.0 ; 
 while(!pq.empty()){ 
 ll u = pq.top().second; 
 pq.pop() ; 
 if(vis[u]) continue ; 
 vis[u] = 1 ; 
 for(auto it: ad[u]){ 
 ll v = it.first ; 
 double w = it.second ; 
 if(dist[u]*w > dist[v]) { 
 dist[v] = dist[u]*w , pq.push({dist[v] , v}); 
 }}} 
 return dist[n] ;} 
 int main(){ 
 double dp[101][101] ; 
 while(1){ 
 ll n , x, y , m, p; 
 scanf("%lld", &n) ; 
 for( ll i = 1 ; i <= 100 ; i++)ad[i].clear() ; 
 if(n == 0) break ; 
 scanf("%lld", &m) ; 
 for( ll i = 0 ; i < m ; i++){ 
 scanf("%lld %lld %lld", &x , &y , &p) ; 
 ad[x].pb({y,p*1.0/100.0}) ; 
 ad[y].pb({x , p*1.0/100.0}) ; 
 } 
 double ans = dijkstra(n)*100.0; ; 
 printf("%0.6f percent\n", ans); 
 
 } 
 
 } 

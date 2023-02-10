// an array of N integers indexed from 1 to N, and q queries,
//ch in the form i j, you have to find the number of distinct integers 
//om index i to j (inclusive).

#include<bits/stdc++.h>
using namespace std;
#define ll      long long int
#define pb      push_back
#define T ll time;        cin >> time; while(time--)
#define FastIo  ios_base::sync_with_stdio(false);cin.tie(NULL) ;
const ll mod = 998244353  , N = 1e6+10 , INF = 5e17 ;
ll A[N] , cnt[N] , tot , block = sqrt(N);
struct query
{
    ll l , r , ind ;
}Ar[N];

bool MoSort(query a , query b){
    if(a.l/block != b.l/block)
        return a.l/block <= b.l/block ;
    return a.r <= b.r ;
}

void add(ll i){
   if(!cnt[A[i]]) tot++ ;
   cnt[A[i]]++ ;
}

void remove(ll i){
    cnt[A[i]]-- ;
    if(!cnt[A[i]]) tot-- ;
}

int main(){ 
FastIo ;
ll tt = 1 ;
T{
ll n , q , x, y , L = - 1 , R = - 1;
cin >> n >> q ;
vector < ll > ans(n+1) ;
for( ll i = 1 ; i <= n ; i++) cin >> A[i] , cnt[A[i]] = 0 ;

for( ll i = 0 ; i < q ; i++){
    cin >> x >> y ;
    Ar[i].l = x , Ar[i].r = y , Ar[i].ind = i+1 ;
}

sort(Ar , Ar + q , MoSort) ;
tot = 0 ;
L = R = Ar[0].l ;
add(L) ;
for( ll i = 0 ; i < q ; i++){
    while(Ar[i].l < L) add(--L) ;
    while(Ar[i].r > R) add(++R) ;
    while(Ar[i].l > L) remove(L++) ;
    while(Ar[i].r < R) remove(R--)  ;
    ans[Ar[i].ind] = tot ; 
}
cout << "Case " << tt << ":" << endl ;
for( ll i = 1 ; i <= q ; i++)
  cout << ans[i] << endl ;

tt++ ;
}

}

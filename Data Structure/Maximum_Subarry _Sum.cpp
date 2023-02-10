#include<bits/stdc++.h>
using namespace std;
#define ll      long long int
#define pb      push_back
#define T ll time;        cin >> time; while(time--)
#define FastIo  ios_base::sync_with_stdio(false);cin.tie(NULL) ;
const ll mod = 1e9+7  , N = 2e5+100 , INF = 5e17 ;
ll ar[N] ;
struct Data{
    ll FirstMax , SecondMax;
}Tree[4*N];

Data Combine(Data l , Data r){
    Data Res ;
    if(l.FirstMax < r.FirstMax){
        Res.FirstMax = r.FirstMax;
        Res.SecondMax = l.FirstMax ;
    }
    else{
        Res.FirstMax = l.FirstMax ;
        Res.SecondMax = r.FirstMax ;
    }
    if(l.SecondMax > Res.SecondMax) Res.SecondMax = l.SecondMax ;
    if(r.SecondMax > Res.SecondMax) Res.SecondMax = r.SecondMax ;

    return Res ;
}

void Build(ll Par , ll b , ll e){
    if(b == e) {
    Tree[Par].FirstMax = ar[b] ;
    return ;
    }
    ll mid = (b + e) / 2 , Left = Par*2 , Right = Left + 1 ;
    Build(Left , b , mid) ;
    Build(Right , mid+1 , e) ;
    Tree[Par] = Combine(Tree[Left] , Tree[Right] ) ;
}

void Update(ll Par , ll b , ll e , ll pos , ll NewVal){
    if(pos < b or pos > e) return ;
    if(b >= pos and e <= pos){
        Tree[Par].FirstMax = NewVal ;
        Tree[Par].SecondMax = 0 ;
        return ;
    }
    ll mid = (b + e) / 2 , Left = Par*2 , Right = Left + 1 ;
    Update(Left , b , mid , pos , NewVal) ;
    Update(Right , mid + 1 , e , pos , NewVal) ;
    Tree[Par] = Combine(Tree[Left] , Tree[Right]) ;
}

Data Query(ll Par , ll b , ll e, ll l , ll r){
    if(r < b or l > e) return {0 , 0} ;
    if(l <= b and r >= e) return Tree[Par] ;
    ll mid = ( b + e ) / 2 , Left = Par*2 , Right = Left + 1 ;
    Data One , Two  , ret;
    One = Query(Left , b , mid , l , r ) ;
    Two = Query(Right , mid + 1, e , l , r) ;
    ret =   Combine(One, Two) ;
    return ret ;
}
  

int main(){   
   FastIo ;
   ll n , q , x, y;
   cin >> n ;
   for( ll i = 1 ; i <= n ; i++) cin >> ar[i] ;
   cin >> q ;
   Build(1 , 1, n) ;
   char ch ;
   for( ll i = 0 ; i < q ; i++){
     cin >> ch >> x >> y ;
     if(ch == 'U')
        Update(1 , 1 , n , x , y) ;
     if(ch == 'Q'){
        Data ans = Query(1 , 1 , n , x , y);
        cout << (ans.FirstMax + ans.SecondMax) << endl ;
     }
     
   }


}

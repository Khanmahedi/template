 struct DSU{
    vector < ll > Par, S ;
    DSU(ll n){
     Par.assign(n+10 , 0) ;
     S.assign(n+10 , 0) ;
     for( ll i = 0 ; i <= n ; i++) Par[i] = i, S[i] = 1;
    }
    ll find_par(ll x){
      if(x == Par[x]) return x ;
      return Par[x] = find_par(Par[x]) ;
    }
    void Marge(ll x , ll y){
     ll para = find_par(x) ;
     ll parb = find_par(y) ;
     if(para != parb){ 
         if(S[parb] > S[para]) swap(para , parb) ;
         Par[parb] = para ;
         S[para]+=S[parb] ;
         S[parb] = 0 ;
     }
    }
 };

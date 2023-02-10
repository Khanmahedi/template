struct SPARSE_TABLE{
      ll st[3000][22] = {} , n;
      SPARSE_TABLE(ll _n , vector < ll > v){
         n = _n ;
         for( ll i = 0 ; i < n ; i++) st[i][0] = v[i] ;
      }
      void BuildTree(){
        for( ll i = 1 ; i <= 21 ; i++){
           for( ll j = 0 ; j + (1ll << i) <= n ; j++){
            st[j][i] = __gcd(st[j][i - 1] , st[j + (1ll << (i - 1))][i - 1]) ;
           }
        }
      }
      
      ll Query(ll l , ll r){
        ll len , one , two , k ;
        --l , --r ;
        len = (r - l + 1) , k = log2(len) ;
        one = st[l][k] , two = st[l + len - (1ll << k)][k] ;
        return __gcd(one , two) ;
      }
};

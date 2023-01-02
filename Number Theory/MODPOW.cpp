ll modpow(ll a, ll b){
  ll c = 1 ;
  while(b){
    if(b&1) c = c*a%mod ;
    a = a*a%mod;
    b >>= 1 ;
  }
  return c ;
}
 

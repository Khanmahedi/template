
   ll BigMod(ll a, ll b)
  {
      if(b==0) return 1;
      ll x=BigMod(a, b/2);
      if(b%2==0) return (x*x)%mod;
      x=(x*x)%mod;
      return (x*a)%mod;
  }
  
  ll Inv(){
    for( ll i = 0 ; i < sz - 1; i++)
      inv[i] = BigMod(fact[i] , mod-2)%mod ;
  }
  
  ll nCr(ll n , ll r){
    ll down = (inv[r]*inv[n-r])%mod ;
    return (fact[n]*down)%mod ;
  }

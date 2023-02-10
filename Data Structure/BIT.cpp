struct BIT
{ 
  ll n ;
  vector < ll > BT ;
  BIT(ll _n) { BT.assign(_n+1 , 0) ; n = _n ;}
  
  void Update(ll pos , ll val){
    while(pos <= n ) BT[pos]+=val , pos+=(pos&-pos) ;
  }
  ll Query(ll pos){
    ll sum = 0 ;
    while(pos > 0) sum+=BT[pos], pos-=(pos&-pos) ;
    return sum ;
  }
};

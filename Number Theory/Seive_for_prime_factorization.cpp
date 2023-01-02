vector < ll > spf(10000010) ;
void seive_For_prime_fac(ll nmax){
for( ll i = 0 ; i <= nmax ; i++) spf[i] = i ;
for( ll i = 2 ; i*i <= nmax ; i++){
if(spf[i] == i)
  for( ll j = i*i ; j <= nmax ; j+=i)
  if(spf[j] == j)spf[j] = i ;
}
}

vector < ll > getFactorization(ll x ){
vector < ll > ret ;
while( x != 1){
  ret.push_back(spf[x]) ;
  x = x / spf[x] ;
}
return ret ;
}

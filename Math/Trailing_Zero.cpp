void sieve(){
 int maxN = 1000001 ; 
 for( ll i = 1 ; i <= maxN ; i++) is_prime[i] = 1 ; 
 is_prime[0] = is_prime[1] = 0 ; 
 for( ll i = 2 ; i <= maxN ; i++){ 
 if(is_prime[i]){ 
 prime.push_back(i) ; 
 for( ll j = i*i ; j <= maxN ; j+=i) 
 is_prime[j] = 0 ; } } } 
int main(){ 
 sieve() ; 
 ll tt = 1 ; 
 T{ 
 ll n , sqroot , ans = 1 , cnt = 0 ; 
 cin >> n ; 
 sqroot = sqrt(n + 0.1) ; 
 for( ll i = 0 ; i < prime.size() and prime[i] <= sqrt(n + 0.1) ; i++){ 
 cnt = 1 ; 
 if(n == 1) { 
 break; 
 } 
 if(n % prime[i] == 0) 
 while(n%prime[i] == 0) n/=prime[i] , cnt++ ; 
 ans*=cnt ; 
 } 
 printf("Case %lld: ", tt++); 
 if(n > 1) ans*=2 ; 
 cout << (ans - 1) << endl ; 
}}

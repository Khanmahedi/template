const ll Maxn = 1e4+10 ;   
ll last, sz, tree[Maxn][27], link[Maxn], len[Maxn];
ll cnt[Maxn] , num[Maxn];
ll Start[Maxn], End[Maxn];
struct Palindromic_Tree{    // see value of Maxn
   string s ;
   ll t , idx , n;

   Palindromic_Tree(string &ss){
        s = ss ;
        n = s.size() ;
   }
   inline void extend(ll p){
      while(s[p - len[t] - 1] != s[p]) t = link[t] ;    // find first suitable suffix 
      ll x = link[t] ;
      while(s[p - len[x] - 1] != s[p]) x = link[x] ;    // find second suitable suffix for linking
      ll c = s[p] - 'A' ;                               // charge according to the requrements
      if(!tree[t][c]){
        tree[t][c] = ++idx ;
        len[idx] = len[t] + 2 ;
        link[idx] = len[idx] == 1? 2 : tree[x][c] ;
        num[idx] = 1 + num[link[idx]] ; 
        Start[idx] = p - len[idx] + 1 ;
        End[idx] = p ;                
      }
      t = tree[t][c] , ++cnt[t] ;
   }

   void init(){
     memset(tree , 0 , sizeof tree) ;
     memset(link, 0 , sizeof link) ;
     memset(cnt , 0 , sizeof cnt) ;
     len[1] = -1, len[2] = 0 ;
     link[1] = 1 , link[2] = 1 ;
     t = idx = 2 ;

   }
   void count(){ // number of occurence 
    for( ll i = idx ; i >= 0 ; i--) cnt[link[i]]+=cnt[i] ;    
   }

 };

#define MAX_N 2000100                        
int RA[MAX_N], tempRA[MAX_N] , RANK[MAX_N];                 
int SA[MAX_N], tempSA[MAX_N], LCP[MAX_N];                 
int c[MAX_N];
struct SUffix_Array{         // 0 based index
      string T ;
      int n ;
    SUffix_Array(string s){            // see here
           T = s ;
           n = s.size() ;
           BuildSA() ;
           Get_Lcp() ;

    }                                  
void countingSort(int k) {                      
            int i, sum, maxi = max(300, n);                
            memset(c, 0, sizeof c);  
            for (i = 0; i < n; i++)   
            c[i + k < n ? RA[i + k] : 0]++;
            for (i = sum = 0; i < maxi; i++){
              int t = c[i]; c[i] = sum; sum += t; 
            }
            for (i = 0; i < n; i++)  
              tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
            for (i = 0; i < n; i++)     
            SA[i] = tempSA[i];
}
void BuildSA() {        
        int i, k, r;
        for (i = 0; i < n; i++) RA[i] = T[i];          
        for (i = 0; i < n; i++) SA[i] = i;           
        for (k = 1; k < n; k <<= 1) {                 
        countingSort(k);                              
        countingSort(0);                               
        tempRA[SA[0]] = r = 0;                        
        for (i = 1; i < n; i++)                       
        tempRA[SA[i]] =                              
        (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
        for (i = 0; i < n; i++)                        
        RA[i] = tempRA[i];
        if (RA[SA[n-1]] == n-1) break;                 
} }
 // kasai ALgorithm for LCP Array
void Get_Lcp(){  // 0 indexed based
  for(ll i = 0 ; i < n ; i++) RANK[SA[i]] = i ;
  ll k = 0 ;
  for( ll i = 0 ; i < n ; i++){
      ll ind1 = RANK[i] , ind2 = ind1 - 1 ;
      if(ind1 != 0){
         while(T[i+k] == T[SA[ind2]+k]) k++ ;
         LCP[RANK[i]] = k ;if(k > 0) k-- ;
      }}
      return;
}
  void print(){
    for( ll i = 0 ; i < n ; i++){
      ll start = SA[i] ;
      for( ll j = start ; j < n ; j++) cout << T[j] ;
        cout << endl ;
    }
    cout << "Suffix Array : " << endl ;
    for( ll i = 0 ; i < n ; i++) cout << SA[i] << " " ;
      cout << endl ;
    cout << "LCP : " << endl;
    for(ll i = 0 ; i < n ; i++) cout << LCP[i] << " " ;
      cout << endl ;
  }

};

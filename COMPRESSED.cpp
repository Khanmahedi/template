   void Compressed(vector < ll > &a , vector < ll > &temp){
     sort(temp.begin() , temp.end()) ;
     temp.erase(unique(temp.begin() , temp.end()) , temp.end()) ;
     for( ll i = 0 ; i < a.size() ; i++)
       a[i] = upper_bound(temp.begin() , temp.end(), a[i]) - temp.begin() ;
   }

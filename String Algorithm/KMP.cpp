struct KMP{
  vector < ll > lps ;
  string text , pattern ;
  KMP(string s , string pat){
     text = s , pattern = pat ;
     lps.assign(pattern.size(), 0) ;
     this->LPS() ;
  }
  void LPS(){
    ll index = 0 ;
    for( ll i = 1 ; i < pattern.size() ; ){
        if(pattern[index] == pattern[i]){ 
            lps[i] = index + 1 , ++index , ++i ; 
          }
        else{
            if(index != 0 ) index = lps[index - 1] ;
            else lps[i] = index , ++i ;
        }
      }
    }
  ll kmp(){
    ll i = 0 , j = 0 , cnt = 0; // i = text index , j = pattern index ;
    while(i < text.length()){
      if(text[i] == pattern[j]) i++ , j++ ;
      else{
        if(j != 0) j = lps[j - 1] ;
        else i++ ;
      }
      if(j == pattern.length()){
        if(j != 0) j = lps[j - 1] ;
        else i++ ;
        cnt++ ;
      }
  }
  return cnt ;
}};

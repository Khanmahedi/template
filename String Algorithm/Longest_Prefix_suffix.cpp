vector < ll > LPS(string pattern){
    vector < ll > lps(pattern.size() , 0) ;
    ll index = 0 ;
    for( ll i = 1 ; i < pattern.size() ; ){
        if(pattern[index] == pattern[i]){ 
            lps[i] = index + 1 ;
            ++index , ++i ;
        }
        else {
            if(index != 0 ) index = lps[index - 1] ;
            else lps[i] = index , ++i ;
        }
    }
    return lps ;
}

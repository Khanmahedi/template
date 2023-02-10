  
void dfs(ll node , ll par ){
    // Flat[++timer] = node ;
    // Start[node] = timer ;
    // LCA[node][0] = par ;
    for(auto child : ad[node]){
        if(child != par){
        // Level[child]+=Level[node] + 1 ;
        dfs(child , node) ;
    }
} 
    // Flat[++timer] = node ;
    // End[node] = timer ; 
}

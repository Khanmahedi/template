 vector < ll > ad[N] ;
  bool dfs(ll node , ll par){
    vis[node] = 1 ;
    for(auto child: ad[node]){
        if(!vis[child]){
          if(dfs(child , node) == true) return true ;
        }
        else if(child != par) return true ;
    }
    return false ;
  }

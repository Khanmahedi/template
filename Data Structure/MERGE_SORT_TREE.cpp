int i = 0 ; 
int j = 0 ; 
while(i < st[2*node].size() and j < 
st[2*node+1].size()){ 
 
 if(st[2*node][i] <= st[2*node+1][j]) 
 st[node].pb(st[2*node][i]) , i++ ; 
 else st[node].pb(st[2*node][j]), j++ ; 
} 
while(i < st[2*node].size()) 
 st[node].pb(st[2*node][i]), i++ ; 
while(j < st[2*node + 1].size()) 
 st[node].pb(st[2*node + 1][j]) , j++ ;

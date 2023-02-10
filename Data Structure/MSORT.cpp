bool MoSort(query a , query b){
    if(a.l/block != b.l/block)
        return a.l/block < b.l/block ;
    return a.r < b.r ;
}

MLOPP
    while(Ar[i].l < L) add(--L) ; 
    while(Ar[i].r > R) add(++R) ;
    while(Ar[i].l > L) remove(L++) ;
    while(Ar[i].r < R) remove(R--) ;

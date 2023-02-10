       for( ll i = 0 ; i < N ; i++){
                C[i][0] = C[i][i] = 1 ;
                for( ll j = 1 ; j < i ; j++)
                    C[i][j] = (C[i-1][j] % mod + C[i-1][j-1] % mod) % mod ;
            }

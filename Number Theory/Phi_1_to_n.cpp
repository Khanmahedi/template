ll phi[sz] ;
void phi_1_to_n() {
    phi[0] = 0;
    phi[1] = 1;
    for (ll i = 2; i < sz; i++)
        phi[i] = i;

    for (ll i = 2; i < sz; i++) {
        if (phi[i] == i) {
            for (ll j = i; j < sz; j += i)
                phi[j]-= phi[j] / i;
        }
    } 
}

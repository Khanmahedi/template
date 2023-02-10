vector<bool> is_prime(N+1, true);
void Sieve(){
is_prime[0] = is_prime[1] = false;
for (ll i = 2; i * i <= N; i++) {
    if (is_prime[i]) {
        for (ll j = i * i; j <= N; j += i)
            is_prime[j] = false;
    }
}
}

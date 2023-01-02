vector<ll> prime;
bool is_composite[N];
ll phi[N];
ll coprime_pairs[N];
 
void sieve(int n = N) {
  fill(is_composite, is_composite + n, false);
  phi[1] = 1;
 
  for (int i = 2; i < n; i++) {
    if (!is_composite[i]) {
      prime.push_back(i);
      phi[i] = i - 1;
    }
    for (int j = 0; j < prime.size() && i * prime[j] < n; j++) {
      is_composite[i * prime[j]] = true;
      if (i % prime[j] == 0) {
        phi[i * prime[j]] = phi[i] * prime[j];
        break;
      }
      else {
        phi[i * prime[j]] = phi[i] * phi[prime[j]];
      }
    }
  }
 
  coprime_pairs[1] = 0;
  for (int i = 2; i < n; i++) {
    coprime_pairs[i] = coprime_pairs[i - 1] + phi[i];
  }
}

const ll MOD1 = 127657753, MOD2 = 987654319;
const ll p1 = 998244353, p2 = 1e9+7;

 ll BigMod(ll a, ll b , ll mod)
{
    if(b==0) return 1;
    ll x=BigMod(a, b/2 , mod);
    if(b%2==0) return (x%mod*x%mod)%mod;
    x=(x%mod*x%mod)%mod;
    return (x%mod*a%mod)%mod;
}
ll ip1, ip2;
pair<ll, ll> pw[N], ipw[N];
void prec() {             
    pw[0] =  {1, 1};
    for (int i = 1; i < N; i++) {
        pw[i].first =  pw[i - 1].first * p1 % MOD1;
        pw[i].second = pw[i - 1].second * p2 % MOD2;
    }
    ip1 = BigMod(p1, MOD1 - 2, MOD1);
    ip2 = BigMod(p2, MOD2 - 2, MOD2);
    ipw[0] =  {1, 1};
    for (int i = 1; i < N; i++) {
        ipw[i].first =  ipw[i - 1].first * ip1 % MOD1;
        ipw[i].second = ipw[i - 1].second * ip2 % MOD2;
    }
}
struct Hashing {               // don't forget to call prec() ;
    ll n; vector<ll> s; // 0 - indexed
    vector<pair<ll, ll>> hs; // 1 - indexed // (you have to change for string)
    Hashing() {}
    Hashing(vector<ll> _s) {
        n = _s.size(); s = _s;
        hs.emplace_back(0, 0);
        for (int i = 0; i < n; i++) {
            pair<ll, ll> p;
            p.first = (hs[i].first +  pw[i].first * (s[i] % MOD1 + MOD1) % MOD1) % MOD1;
            p.second = (hs[i].second +  pw[i].second * (s[i] % MOD2 + MOD2) % MOD2) % MOD2;
            hs.push_back(p);
        }
    }
    pair<ll, ll> GetHash(ll l, ll r) { // 1 - indexed
        pair<ll, ll> ans;
        ans.first = (((hs[r].first - hs[l - 1].first + MOD1) % MOD1) * ipw[l - 1].first % MOD1) % MOD1;
        ans.second = (((hs[r].second - hs[l - 1].second + MOD2) % MOD2) * ipw[l - 1].second % MOD2) % MOD2;
        return ans;
    }
};

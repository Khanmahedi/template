 ll BigMod(ll a, ll b)
{
    if(b==0) return 1;
    ll x=BigMod(a, b/2);
    if(b%2==0) return (x*x);
    x=(x*x);
    return (x*a);
}

ll extend_gcd(ll a, ll b, ll& x, ll& y)
{
  ll t;
  if (b == 0)
  {
    x = 1, y = 0; 
    return a;
  }
  ll d = extend_gcd(b, a % b, x, y);
  t = x, x = y;             
  y = t - a / b * y;          
  return d;    
}

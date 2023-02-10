int a[N];
struct ST {
  long long t[4 * N], lazy[4 * N];
  ST() {
    memset(t, 0, sizeof t);
    memset(lazy, 0, sizeof lazy);
  }
  inline void pushdown(int n, int b, int e) {
    if (lazy[n] == 0) return;
    int l = n << 1 , r = l | 1 ;
    t[n]+=lazy[n] ;
     if (b != e) {
      lazy[l] = lazy[l] + lazy[n];
      lazy[r] = lazy[r] + lazy[n];
    }
    lazy[n] = 0;
  }
  void build(int n, int b, int e) {
    lazy[n] = 0;
    if (b == e) {
      t[n] = a[b];
      return;
    }
    int mid = (b + e) >> 1 , l = n << 1 , r = l | 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    t[n] = max(t[l] , t[r]) ;
  }
  void update(int n, int b, int e, int i, int j, long long v) {
    pushdown(n, b, e);
    if (j < b || e < i) return;
    if (i <= b && e <= j) {
      lazy[n] = v; //set lazy
      pushdown(n, b, e);
      return;
    }
    int mid = (b + e) >> 1 , l = n << 1 , r = l |1;
    update(l, b, mid, i, j, v);
    update(r, mid + 1, e, i, j, v);
    t[n] = max(t[l] , t[r]) ;
  }
  long long query(int n, int b, int e, int i, int j) {
    pushdown(n, b, e);
    if (i > e || b > j) return 0; //return null
    if (i <= b && e <= j) return t[n];
    int mid = (b + e) >> 1 , l = n << 1 , r = l | 1;
    return max(query(l, b, mid, i, j), query(r, mid + 1, e, i, j));
  }
}t;

#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define pb   push_back
#define T int time;        scanf("%d", &time); while(time--)
#define FastIO         ios_base::sync_with_stdio(false);cin.tie(NULL)
        
        ll dx[] = {1 , -1 , 0 , 0} ;
        ll dy[] = {0 , 0 , 1 , -1} ;
        struct pqq{
            ll a , b ;
        };

        struct comp{
           bool operator()(pqq &p1, pqq &p2)
           {
             if(p1.a > p2.a) return true ;
             if(p1.a == p2.a and p1.b > p2.b) return true ;
             return false ; 
           }

        };

        bool com(pair < ll , ll > &p1 , pair < ll , ll > &p2){
                if(p1.first < p2.first) return true ;
                if(p1.first == p2.first and p1.second < p2.second) return true ;
                return false ;
        }

           int main(){
            ll tt = 1 ;
                   while(1){
                     ll n , r , x , y , cnt = 1;
                     cin >> n >> r ;
                     if(n == r and n == 0) break ;
                     vector < ll > ad[n+10] , ans;
                     ll in[n+10] = {} , vis[n+10] = {};
                     for( ll i = 1 ; i <= r ; i++){
                        cin >> x >> y ;
                        ad[x].pb(y) ;
                        in[y]++ ;

                     }

            // priority_queue <pqq ,vector < pqq > ,  comp> pq ;
              queue < ll > pq ;

            for( ll i = 1  ; i <= n ; i++){
                if(in[i] == 0) pq.push( i) ;
            }

            while(!pq.empty()){
                ll u = pq.front() ;
                pq.pop() ;
                ans.pb(u) ;

                for( auto it: ad[u]){
                    in[it]-- ;
                    if(in[it] == 0) {
                           pq.push(it) ;
                        }
                       
                                            
                }
            }

            for( ll i = 0 ; i < ans.size() ; i++)
                cout << ans[i] << " " ;
            cout << endl ;
            

 
             }

         }
 

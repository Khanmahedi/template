/*Kingdom of Rohan is under attack! There are N vital army stations. 
  King will decide what army should be guarding what station, 
to get the best strategic advantage against Sauron attacks. 
  All armies are already in some stations, but not necessarily 
  the stations required by the king. As a result armies will have 
  to be moved. Distances between any pair of stations are known. 
  They are not necessarily symmetrical, because road from station A to B could be different than road from B to A.
  When a army moves, it doesn't have to take a direct road and instead can choose to cross other stations, if that results in a shorter path.

Given the distances between stations and king's relocation orders, find the minimum total travel distance for all the armies.*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define pb   push_back
#define T int time;        scanf("%d", &time); while(time--)
#define FastIO         ios_base::sync_with_stdio(false);cin.tie(NULL)
 
           int main(){
            ll tt = 1 ;
 
             T{
                 
               ll dp[100][100] ={} , n , inf = 1e17 , x , r , y , ans = 0 ;
               cin >> n ;
               for( ll i = 1 ; i <= 50 ; i++){
                for( ll j = 1 ; j <= 50 ; j++){
                    if(i != j) dp[i][j] = inf ;
                }
               }
               for( ll i = 0 ; i < n ; i++){
                for( ll j = 0 ; j < n ; j++){
                    scanf("%lld", &x) ;
                    dp[i+1][j+1] = x ; 
                }
               }

               for( ll k = 1 ; k <= 50 ; k++){
                for( ll i = 1 ; i <= 50 ; i++){
                    for( ll j = 1 ; j <= 50 ; j++){
                        if(dp[i][j] > (dp[i][k] + dp[k][j])){
                            dp[i][j] = dp[i][k] + dp[k][j] ;
                        }
                    }
                }
               }

               scanf("%lld", &r) ;
               for( ll i = 0 ; i < r ; i++){
                scanf("%lld %lld", &x , &y) ;
                ans+=dp[x][y] ;
               }
               printf("Case #%lld: %lld\n", tt, ans);
               tt++ ;
  
             }
          }

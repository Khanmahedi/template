   for( ll i = n  ; i >= 1 ; i--){
      while(!st.empty() and v[st.back()] <= v[i]) 
        st.pop_back() ;
      ll next = st.empty() ? n+1 : st.back() ;
      ad[next].pb(i) ;
      st.push_back(i);
   }

struct node 
{ 
 node* edge[26]; 
 int endmark; 
 node() 
 { 
 endmark = 0; 
 for (int i = 0; i < 26; i++) edge[i] = NULL;
   }
}*root; 

void add( string &s) 
{ 
 node *cur = root; 
 for (int i = 0; s[i]; i++) 
 { 
 int c = s[i] - 'a'; 
 if (cur->edge[c] == NULL) 
 { 
 cur->edge[c] = new node(); 
 } 
 cur = cur->edge[c]; 
 } 
 cur->endmark = 1; 
} 

void display(node *cur, string str) 
{ 
 if (cur->endmark) ans.pb(str); 
 for (int j = 0; j < 26; j++) 
 { 
 if (cur->edge[j] != NULL) 
 { 
 display(cur->edge[j], str + char(j + 'a')); 
 } 
 } 
} 

void search(node *root, string s1) 
{ 
 node *cur = root; 
 int n = s1.size(); 
 for (int i = 0; i < n; i++) 
 { 
 int c = s1[i] - 'a'; 
 if (cur->edge[c] == NULL) return; 
 cur = cur->edge[c]; 
 } 
  
 
 for (int i = 0; i < 26; i++) 
 { 
 if (cur->edge[i] != NULL) 
 { 
 display(cur->edge[i], s1 + (char)(i + 'a')); 
 } 
 
 } 
} 

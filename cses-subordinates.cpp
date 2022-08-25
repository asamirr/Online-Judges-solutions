#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 2e5 + 10;
vector<int> adj[N];
vector<int> dp(N, 0);
bool vis[N];
 
void dfs(int u){
    int ans = 0;
    vis[u] = true;
    for(auto child : adj[u]){
        if(!vis[child]){
            dfs(child);
            ans += 1 + dp[child] ;
            
        }
    }
    dp[u] = ans;
}
 
int main()
{
    
    int x, n;
    cin >> n;
    int st = 2;
    for(int i = 0 ; i < n-1; i++){
        cin >> x;
        adj[x].push_back(st++);
    }   
    dfs(1);
    
    for(int i = 1; i <= n; i++)
        cout << dp[i] << " ";
    
    return 0;
}

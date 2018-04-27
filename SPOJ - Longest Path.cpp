#include <bits/stdc++.h>

using namespace std;

vector <int> adj[10005];
int vis[100010]


void DFS(){
    vis[u] = 1;

}

int main(){
     int n, u, v;
     cin >> n;
     for(int i = 0; i < n-1; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);    
    }
    for(int i = 1; i <= n; i++){
        
    }
    DFS(a);
    cout << mx;
}
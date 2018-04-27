#include <bits/stdc++.h>

using namespace std;

int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

string a, b;
int vis[11][11];
int dis[11][11];

void bfs(int x1, int x2, int y1, int y2){
    memset(vis, 0, sizeof vis);
    queue<pair<int, int>> q;
    q.push({x1, x2});
    vis[x1][x2] = 1;
    dis[x1][x2] = 0;
    while(!q.empty()){
        pair<int, int> top = q.front();
        q.pop();
        if(top.first == y1 && top.second == y2){
            cout << "To get from " << a << " to " << b << " takes " << dis[top.first][top.second] << " knight moves." << endl;
            return;
        }
        for(int i = 0; i < 8; i++){
            int u = top.first + dx[i];
            int v = top.second + dy[i];
            if(u > 0 && u <= 8 && v > 0 && v <= 8 && !vis[u][v]){
                vis[u][v] = 1;
                dis[u][v] = dis[top.first][top.second] + 1;
                q.push({u, v});
            }
        }
    }
}

int main()
{
    while(cin >> a >> b) {
        int s1 = a[0] - 96;
        int s2 = a[1] - '0';
        int d1 = b[0] - 96;
        int d2 = b[1] - '0';
        bfs(s1, s2, d1, d2);
    }
    return 0;
}

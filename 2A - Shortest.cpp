#include <bits/stdc++.h>
 
using namespace std;
 
int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};
 
string a, b;
int s1, s2, d1, d2, dist[9][9];
pair<int, int> par[9][9];
vector<string> path;

void bfs(){
	dist[s1][s2] = 0;
	queue<pair<int, int>> q;
	q.push({s1, s2});
	while(q.size()){
		pair<int, int> top = q.front();
		q.pop();
		for(int i = 0; i < 8; i++){
			int u = top.first + dx[i];
			int v = top.second + dy[i];
			if(u > 0 && u <= 8 && v > 0 && v <= 8 && dist[u][v] == -1){
				q.push({u, v});
				dist[u][v] = dist[top.first][top.second] + 1;
				par[u][v] = top;
			}
		}
	}
}
string grid(int fromI, int fromJ, int toI, int toJ){
	string ans = "";
	if(fromI - 1 == toI)
		ans += 'L';
	else if(fromI + 1 == toI)
		ans += 'R';
	if(fromJ - 1 == toJ)
		ans += 'D';
	else if(fromJ + 1 == toJ)
		ans += 'U';
	return ans;
}
void build(){
	int i = par[d1][d2].first;
	int j = par[d1][d2].second;
	path.push_back(grid(i, j, d1, d2));
	while(i != s1 || j != s2){
		int tx = i;
		int ty = j;
		i = par[tx][ty].first;
		j = par[tx][ty].second;
		path.push_back(grid(i, j, tx, ty));
	}
}

int main() {
	memset(dist, -1, sizeof dist);
	
	cin >> a >> b;
 
	int s1 = a[0] - 'a' + 1;
	int s2 = a[1] - '0';
	int d1 = b[0] - 'a' + 1;
	int d2 = b[1] - '0';
	
	if(s1 == d1 && s2 == d2){
		cout << "0";
		return 0;
	}
	
	bfs();
	build();
	
	cout<< dist[d1][d2] << endl;
	
	// for(int i=path.size() - 1; i >= 0; i--)
	// 	cout<<path[i]<<endl;
	return 0;
}
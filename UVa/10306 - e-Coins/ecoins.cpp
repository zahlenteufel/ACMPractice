#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <queue>

using namespace std;

#define forn(i,n) for(int i=0;i<int(n);++i)
#define forsn(i,s,n) for(int i=int(s);i<int(n);++i)
#define INF 1000000

int n, m, S;
vector<pair<int,int> > ecoins;
vector<vector<int> > dist;

void bfs() {
	queue<pair<int,int> > q;
	int x, y, nx, ny;
	dist = vector<vector<int> >(310,vector<int>(310,INF));
	vector<vector<bool> > vis(310,vector<bool>(310,false));
	dist[0][0] = 0;
	q.push(make_pair(0,0));
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		forn(i,m) {
			nx = ecoins[i].first;
			ny = ecoins[i].second;
			if (x+nx <= S && y+ny <= S && !vis[x+nx][y+ny]) {
				dist[x+nx][y+ny] = dist[x][y] + 1;
				vis[x+nx][y+ny] = true;
				q.push(make_pair(x+nx,y+ny));
			}
		}
	}
}

int main() {
    //freopen("entrada.in","r",stdin);
	cin >> n;
	forn(prob,n) {
		cin >> m >> S;
		ecoins = vector<pair<int,int> >(m);
		forn (t,m) {
			int x, y;
			cin >> x >> y;
			ecoins[t] = make_pair(x,y);
		}
		int res = INF;
		bfs();
		forn (x,S+1)
			forn (y,S+1)
				if (x*x+y*y==S*S)
					res = min(res,dist[x][y]);
		if (res == INF)
			cout << "not possible" << endl;
		else
			cout << res << endl;
	}
	
	return 0;
}

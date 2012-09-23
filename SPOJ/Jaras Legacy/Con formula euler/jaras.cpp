//~ 
//~ http://www.spoj.pl/problems/JARA/
//~ 
#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <climits>
#include <map>

#define forn(i,n) for(int i=0;i<int(n);i++)
#define isIn(e,c) (find((c).begin(),(c).end(),e) != (c).end())
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define forall(it, c) for(typeof((c).begin()) it = (c).begin();it!=(c).end();++it)

using namespace std;

const int INF = INT_MAX;
vector<vector<int> > ady;
struct fence {
	int x, y, xx, yy;
};

struct infocc {
	int cantAristas, cantNodos;
};

bool vis[100100];

infocc BFS(int ini) {
	infocc res;
	res.cantAristas = res.cantNodos = 0;
	queue<int> q;
	q.push(ini);
	vis[ini] = true;
	while (!q.empty()) {
		int e = q.front(); q.pop();
		res.cantNodos++;
		res.cantAristas += int(ady[e].size());
		forn (i,ady[e].size())
			if (!vis[ady[e][i]]) {
				q.push(ady[e][i]);
				vis[ady[e][i]] = true;
			}
	}
	res.cantAristas /= 2;
	return res;
}

int dameMenorCantCortes() {
	forn (i,ady.size())
		vis[i] = false;
	int res = 0;
	forn (i,ady.size()) {
		if (!vis[i]) {
			infocc cc = BFS(i);
			res += cc.cantAristas - cc.cantNodos + 1;
		}
	}
	
	return res;
}

fence fences[100100];

int main() {
	//~ freopen("test.in", "r", stdin);
	int N;
	while (scanf("%d\n", &N)==1 && N!=-1) {
		map<pair<int, int>, int> endpoints;
		forn (i, N) {
			int x, y, xx, yy;
			scanf("%d %d %d %d\n", &x, &y, &xx, &yy);
			fences[i].x = x; fences[i].y = y; fences[i].xx = xx; fences[i].yy = yy;
			endpoints.insert(make_pair(make_pair(x,y), 0));
			endpoints.insert(make_pair(make_pair(xx,yy), 0));
		}
		int count = 0;
		forall (it, endpoints)
			it->second = count++;
		ady = vector<vector<int> >(endpoints.size());
		forn (i, N) {
			int ind1 = endpoints[make_pair(fences[i].x, fences[i].y)];
			int ind2 = endpoints[make_pair(fences[i].xx, fences[i].yy)];
			ady[ind1].push_back(ind2);
			ady[ind2].push_back(ind1);
		}
		printf("%d\n", dameMenorCantCortes());
	}
	return 0;
}

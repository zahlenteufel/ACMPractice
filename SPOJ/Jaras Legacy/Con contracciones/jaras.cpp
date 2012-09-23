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
int N;
struct fence {
	int x, y, xx, yy;
};

bool vis[100100];

int BFS(int ini) {
	queue<int> q;
	q.push(ini);
	while (!q.empty()) {
		int e = q.front(); q.pop();
		vis[e] = true;
		forn (i,ady[e].size()) {
			if (!vis[ady[e][i]])
				q.push(ady[e][i]);
		}
	}
}

int cantComponentesConexasNoTriviales() {
	forn (i,ady.size())
		vis[i] = false;
	int cantcc = 0;
	forn (i,ady.size()) {
		if (!vis[i] && !ady[i].empty()) {
			BFS(i);
			cantcc++;
		}
	}
	return cantcc;
}

int cantNodosNoTriviales() {
	int res = 0;
	forn (i,ady.size())
		if (!ady[i].empty())
			res++;
	return res;
}

inline void contraerPath(int i, int j, int k) {
	ady[j].clear(); // no lo eliminamos porque sino los indices no sirven mas..
	ady[i].erase(find(ady[i].begin(), ady[i].end(),j));
	ady[k].erase(find(ady[k].begin(), ady[k].end(),j));
	ady[i].push_back(k);
	ady[k].push_back(i);
}

int cantAristas() {
	int m = 0;
	forn (i,ady.size())
		forall (it, ady[i])
			if (i < *it)
				m++;
	return m;
}

int dameMenorCantCortes() {
	queue<int> deg2;
	forn (i,ady.size())
		if (ady[i].size()==2)
			deg2.push(i);
	
	while (!deg2.empty()) {
		int i, j, k;
		j = deg2.front(); deg2.pop();
		i = ady[j][0]; k = ady[j][1];
		if (!isIn(i, ady[k]))
			contraerPath(i,j,k);
	}

	int m_bosque = cantNodosNoTriviales() - cantComponentesConexasNoTriviales();
	return cantAristas() - m_bosque;
}

int main() {
	freopen("test.in", "r", stdin);
	
	while (scanf("%d\n", &N)==1 && N!=-1) {
		vector<fence> fences(N);
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

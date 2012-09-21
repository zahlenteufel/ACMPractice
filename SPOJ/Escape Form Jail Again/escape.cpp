//~ 
//~ https://www.spoj.pl/problems/ESCJAILA/
//~ 
#include <cstdio>
#include <vector>
#include <queue>

#define forn(i,n) for(int i=0;i<int(n);i++)

using namespace std;

char m[110][110];
int N, M;
const int INF = 100000;
vector<vector<int> > adj;

#define closed(x,y) (y*M+x)
#define open(x,y) ((M*N)+closed(x,y))
#define exit (2*N*M)

inline void connect(int x1, int y1, int x2, int y2) { // (x1,y1) -> (x2,y2)
	if (x2 < 0 || x2 >= M || y2 < 0 || y2 >= N) {
		adj[open(x1,y1)].push_back(exit);
		adj[closed(x1,y1)].push_back(exit);
	} else {
		char t2 = m[x2][y2];
		if (t2 == '.') {
			adj[closed(x1,y1)].push_back(closed(x2,y2));
			adj[open(x1,y1)].push_back(open(x2,y2));
		} else if  (t2 == 'D') {
			adj[open(x1,y1)].push_back(open(x2,y2));
		} else if (t2 == 'C') {
			adj[closed(x1,y1)].push_back(closed(x2,y2));
			adj[open(x1,y1)].push_back(closed(x2,y2));
		} else if (t2 == 'O') {
			adj[open(x1,y1)].push_back(open(x2,y2));
			adj[closed(x1,y1)].push_back(open(x2,y2));
		}
	}
}

int BFS(int initialPos) {
	vector<int> dist(2*N*M+1, INF);
	dist[initialPos] = 0;
	queue<int> q;
	q.push(initialPos);
	while (!q.empty()) {
		int v = q.front(); q.pop();
		if (v == exit)
			return dist[v];
		forn (i,adj[v].size()) {
			if (dist[adj[v][i]] == INF) {
				dist[adj[v][i]] = dist[v]+1;
				q.push(adj[v][i]);
			}
		}
	}
	return -1;
}

int main() {
	//~ freopen("test.in", "r", stdin);
	while (scanf("%d %d\n", &N, &M)==2 && N!=-1 && M!=-1) {
		int initX, initY;
		adj = vector<vector<int> >(2*N*M+1,vector<int>());
		forn (y,N) {
			forn (x,M) {
				m[x][y] = getchar();
				if (m[x][y] == 'H') {
					initX = x;
					initY = y;
					m[x][y] = '.';
				}
			}
			getchar(); // get rid of the '\n'
		}
		
		forn (x,M) {
			forn (y,N) {
				connect(x,y,x-1,y);
				connect(x,y,x,y-1);
				connect(x,y,x+1,y);
				connect(x,y,x,y+1);
			}
		}
		printf("%d\n", BFS(closed(initX,initY)));
	}
	return 0;
}

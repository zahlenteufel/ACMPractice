//~ 
//~ http://www.spoj.pl/problems/HACKERS/
//~ 
#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <climits>
#include <cassert>

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)

using namespace std;

int C, L, H;
const long long int INF = INT_MAX;
struct lnk {
	int A, B, V;
};

bool operator<(const lnk& a, const lnk& b) {
	return a.V < b.V;
}

lnk links[3010*3010];
vector<vector<pair<int, int> > > ady;

int UF[3010];
int rank[3010];
 
void initUF(int n){
    forn(i, n)
        UF[i] = i, rank[i] = 0;
}
 
int find(int u){
    if(UF[u] != u) UF[u] = find(UF[u]);
    return UF[u];
}
 
void join(int u, int v){
    int uR = find(u), vR = find(v);
 
    if(uR != vR){
        if(rank[uR] < rank[vR]){
            UF[uR] = vR;
        }else if(rank[uR] > rank[vR]){
            UF[vR] = uR;
        }else{
            UF[uR] = vR;
            rank[vR]++;
        }
    }
}

void kruskal() { // generar el MST del grafo..
	initUF(3010);

	sort(links, links+L);
	
	int cuenta = 0;
	forn (i,L) {
		int A, B, V;
		A = links[i].A;
		B = links[i].B;
		V = links[i].V;
		if (find(A) != find(B)) {
			join(A, B);
			ady[A].push_back(make_pair(V, B));
			ady[B].push_back(make_pair(V, A));
			cuenta++;
			if (cuenta == C-1)
				return;
		}
	}
}

int minPriv(int prev, int S, int T) {
	if (S == T)
		return 1;
	forn (v, ady[S].size()) {
		if (ady[S][v].second != prev) {
			int mp = minPriv(S, ady[S][v].second, T);
			if (mp != -1)
				return max(mp, ady[S][v].first);
		}
	}
	return -1;
}

int main() {
	//~ freopen("test.in", "r", stdin);
	
	while (scanf("%d %d %d\n", &C, &L, &H) == 3 && C != -1 && L != -1 && H != -1) {
		forn (l,L) {
			int A, B, V;
			scanf("%d %d %d\n", &A, &B, &V);
			links[l].A = A;
			links[l].B = B;
			links[l].V = V;
		}
		ady = vector<vector<pair<int, int> > >(C+1);
		
		kruskal();
		forn (h, H) {
			int S, T;
			scanf("%d %d\n", &S, &T);
			
			int res = minPriv(0, S, T);
			
			if (h == 0)
				printf("%d", res);
			else
				printf(" %d", res);
		}
		printf("\n");
	}

	return 0;
}

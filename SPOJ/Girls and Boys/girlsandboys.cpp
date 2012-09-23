//~ 
//~ http://www.spoj.pl/problems/GIRLSNBS/
//~ 
#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)

using namespace std;


int main() {
	freopen("test.in", "r", stdin);
	int G, B;
	while (scanf("%d %d\n", &G, &B) == 2 && G != -1 && B != -1) {
		printf("%d\n", int(ceil(float(max(G,B)) / float((min(G,B)+1)))));
	}
	return 0;
}

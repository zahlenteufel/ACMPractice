#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

#define forn(i,n) for(int i=0;i<int(n);++i)
#define forsn(i,s,n) for(int i=int(s);i<int(n);++i)

vector<vector<int> > binom(15,vector<int>(15,0));

int main() {
    //freopen("entrada.in","r",stdin);
    
	forn(n,15)
		binom[n][0] = 1;
	
	forsn(n,1,15)
		forsn(k,1,n+1)
			binom[n][k] = binom[n-1][k] + binom[n-1][k-1];
	
	int n, k;
	while (cin >> n >> k) {
		int res = 1, exp, usados=n;
		forn(i,k) {
			cin >> exp;
			res *= binom[usados][exp];
			usados-=exp;
		}
		cout << res << endl;
	}
	
	return 0;
}
